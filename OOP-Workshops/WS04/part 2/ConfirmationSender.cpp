#include"ConfirmationSender.h"

using namespace std;
namespace sdds {
   ConfirmationSender::ConfirmationSender() {
      resvArr = nullptr;
      count = 0;
   }
   ConfirmationSender::ConfirmationSender(const ConfirmationSender& og) {
      *this = og;
   }
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& og) {
      *this = move(og);
   }
   ConfirmationSender& ConfirmationSender::operator =(const ConfirmationSender& og) {
      if (&og != this) {
         if (resvArr != nullptr) {
            delete resvArr;
            resvArr = nullptr;
         }
         resvArr = new const Reservation * [og.count];
         for (size_t i = 0; i < og.count; i++) {
            resvArr[i] = og.resvArr[i];
         }
         count = og.count;
      }
      return *this;
   }
   ConfirmationSender& ConfirmationSender::operator =(ConfirmationSender&& og) {
      if (this != &og) {
         if (resvArr != nullptr) {
            delete resvArr;
            resvArr = nullptr;
         }
         resvArr = og.resvArr;
         count = og.count;

         og.resvArr = nullptr;
         og.count = 0;
      }
      return *this;
   }

   ConfirmationSender::~ConfirmationSender() {
      delete[] resvArr;
   }

   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
      bool isUnique = true;
      for (size_t i = 0; i < count; i++) {
         if (resvArr[i] == &res) {
            isUnique = false;
         }
      }
      if (isUnique) {
         const Reservation** temp;
         temp = new const Reservation*[count];
         for (size_t i = 0; i < count; i++) {
            temp[i] = resvArr[i];
         }
         delete[] resvArr;
         count++;
         resvArr = new const Reservation * [count];
         for (size_t i = 0; i < count-1; i++) {
            resvArr[i] = temp[i];
         }
         resvArr[count - 1] = &res;
         delete[] temp;
      }
      return *this;
   }
   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      int matchIndex = -1;
      for (size_t i = 0; i < count; i++) {
         if (resvArr[i] == &res) {
            matchIndex = i;
         }
      }
      if (matchIndex != -1) {
         const Reservation** temp;
         temp = new const Reservation * [count];
         for (size_t i = 0; i < count; i++) {
            temp[i] = resvArr[i];
         }
         delete[] resvArr;
         count--;
         resvArr = new const Reservation * [count];
         for (int i = 0; i < int(count); i++) {
            if(i >= matchIndex){
               resvArr[i] = temp[i+1];
            }
            else {
               resvArr[i] = temp[i];
            }
         }
         delete[] temp;
      }
      return *this;
   }
   std::ostream& operator << (std::ostream& os, const ConfirmationSender& cs) {
      os << "--------------------------\nConfirmations to Send\n--------------------------" << endl;
      if (cs.count <= 0) {
         os << "There are no confirmations to send!" << endl;
      }
      else {
         for (size_t i = 0; i < cs.count; i++) {
            os << *cs.resvArr[i];
         }
      }
      os << "--------------------------" << endl;
      return os;
   }
}