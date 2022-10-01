#include"Queue.h"
using namespace std;
namespace sdds {
   template<typename T, size_t arrCap>
   bool Queue<T, arrCap>::push(const T& item) {
      if (currentCap < arrCap) {
         currentCap++;
         elemArr[currentCap] = item;
         return true;
      }
      return false;
   }

   template<typename T, size_t arrCap>
   T& Queue<T, arrCap>::pop(){
      T* temp;
      T tempObj = elemArr[0];
      temp = new T[currentCap];
      for (int i = 0; i < currentCap; i++) {
         temp[i] = elemArr[i+1];
         elemArr[i] = temp[i];
      }
      currentCap--;
      delete[] temp;
      return tempObj;
   }

   template<typename T, size_t arrCap>
   size_t sdds::Queue<T, arrCap>::size()
   {
      return currentCap;
   }

   template<typename T, size_t  arrCap>
   void Queue<T, arrCap>::display() {
      cout << "hello";
   }

   template<typename T, size_t  arrCap>
   T& Queue<T, arrCap>::operator[](size_t index) {
      return elemArr[index];
   }
}