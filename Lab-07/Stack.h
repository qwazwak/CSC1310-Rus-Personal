/*Title: CSC1310-Lab-7 Stack class
  Author: Rus Hoffman
  Date: 10-24-2018*/
#if !defined(STK_H)
#define STK_H
#include <string>
template<class T> class MyStack {
	private:
		T* dataArray;
		size_t dataCount;
		size_t dataCapacity;
	public:
		MyStack () {
			dataArray = new T[1];
			dataCount = 0;
			dataCapacity = 1;
		}
		~MyStack () {
			delete[] dataArray;
		}
		void push (T input) {
			if(dataCapacity <= (dataCount + 1)) {
				dataCapacity *= 2;
				T* dataArrayNew = new T[dataCapacity];
				for (size_t i = 0; i < dataCount; i++)
					dataArrayNew[i] = dataArray[i];
				delete[] dataArray;
				dataArray = dataArrayNew;
			}
			dataArray[dataCount++] = input;
		}
		T pop () {
			return dataArray[dataCount--];
		}
		bool empty () {
			return dataCount > 0 ? false : true;
		}
};
#endif
