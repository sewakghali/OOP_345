//-------------------------------------------
// OOP345 Project- Milestone 2
// Module: CustomerOrder.h
// Name: Sewak Singh Gill
// Student Id: 159282219
// Email: sgill116@myseneca.ca
//-------------------------------------------
#pragma once
#include<iostream>
#include "Station.h"
namespace sdds {
	struct Item
	{
		std::string m_itemName; //name of item
		size_t m_serialNumber{ 0 }; //item serial number
		bool m_isFilled{ false }; //is item order filled

		Item(const std::string& src) : m_itemName(src) {}; //constructor
	};

	class CustomerOrder {
		std::string m_name {""}; //customer name
		std::string m_product {""}; //order name
		size_t m_cntItem {0}; //number of items in order
		Item** m_lstItem {nullptr}; //items that make up the order

		static size_t m_widthField; //for formattig purposes

	public:
		CustomerOrder(); //default constructor
		CustomerOrder(const std::string&); // custom constructor
		CustomerOrder(CustomerOrder&); //copy constructor --throws error when invoked
		CustomerOrder(CustomerOrder&&) noexcept; // move constructor
		CustomerOrder& operator=(CustomerOrder&) = delete; //delete copy assingment
		CustomerOrder& operator = (CustomerOrder&&); //move assignment
		~CustomerOrder(); //destructor
		bool isOrderFilled()const; //returns true if an order is filled
		bool isItemFilled(const std::string& itemName) const; //returns true if specified item is filled.
		void fillItem(Station& station, std::ostream& os); //sets m_isFilled to true for a particular item in order if its current item in station and is available in inventory
		void display(std::ostream& os) const; //display the order info
	};
}