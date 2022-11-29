/*****************************************************************
Module: TreasureMap.cpp
Name: Sewak Singh Gill
Email: sgill116@myseneca.ca
Student Id: 159282219
Date: November 28, 2022
******************************************************************/

// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include<thread>
#include<functional>
#include<future>
#include "TreasureMap.h"

namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
           std::ofstream binfile(filename, std::ios::out | std::ios::binary);
           if (binfile.good()) {
              binfile.write((const char*)&rows, sizeof(rows));
              binfile.write((const char*)&colSize, sizeof(colSize));

              for (size_t i = 0; i<rows; i++) {
                 binfile.write(map[i].c_str(), colSize);
              }
              binfile.close();
           }
           else {
              throw std::string("File cannot be opened.");
           }

            // END TODO
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
       std::ifstream binfile(filename, std::ios::in | std::ios::binary);
       if (binfile.good()) {
          std::string temp;
          
          //reading rows and colums
          binfile.read((char*)&rows, sizeof(rows));
          binfile.read((char*)&colSize, sizeof(rows));
          //allocating memory for map
          map = new std::string[colSize];
          temp.resize(30);
          for (size_t i = 0; i < rows; i++) {
             binfile.read((char*)&temp[0], colSize);
             map[i] = temp;
          }
          binfile.close();
       }
       else {
          throw std::string("File cannot be opened.");
       }
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
       size_t result = 0;
       using namespace std::placeholders;  // for _1, _2, _3
        std::string temp;
        
        //binding mark to newly derived dig function
        auto dig = std::bind(digForTreasure,_1, mark);
        std::packaged_task<size_t(const std::string&)> t1(dig);
        std::packaged_task<size_t(const std::string&)> t2(dig);
        std::packaged_task<size_t(const std::string&)> t3(dig);
        std::packaged_task<size_t(const std::string&)> t4(dig);
        std::future<size_t> r1 = t1.get_future();
        std::future<size_t> r2 = t2.get_future();
        std::future<size_t> r3 = t3.get_future();
        std::future<size_t> r4 = t4.get_future();

        for (size_t i = 0; i < rows; ++i){
            temp += map[i]; //concatenating string into one
        }
        size_t tsize = temp.size();
        std::thread td1(std::move(t1),temp.substr(0, tsize / 4)); //dividing the string into 4 parts
        std::thread td2(std::move(t2), temp.substr(tsize / 4, (tsize / 2 - tsize / 4)));
        std::thread td3(std::move(t3),temp.substr(tsize / 2, (3 * tsize / 4) - tsize / 2));
        std::thread td4(std::move(t4),temp.substr(3*tsize / 4));

        //merging all the threads
        td1.join();
        td2.join();
        td3.join();
        td4.join();
        
        //getting values from individual future instances from their host threads
        result = r1.get() + r2.get() + r3.get() + r4.get();
        return result;
    }
}