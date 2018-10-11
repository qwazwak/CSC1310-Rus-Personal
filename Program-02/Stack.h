/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Filename:    Stack.hpp
 *  Title:       CSC1310 - Program - 02
 *  Author(s):   Rus Hoffman
 *  Created On:  September 26, 2018
 *
 * * * * * * * * * * * * * * * * * * * * * * * */

#if !defined(STACK_H)
#define STACK_H

#include <iostream>

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

		virtual ~MyStack () {
			delete[] dataArray;
			dataCapacity = 0;
			dataCount = 0;
		}

		void push (T input) {
			if(dataCapacity <= (dataCount + 1)) {
				T* dataArrayNew = new T[dataCapacity * 2];
				for (size_t i = 0; i < dataCount; i++) {
					dataArrayNew[i] = dataArray[i];
				}
				delete[] dataArray;
				dataArray = dataArrayNew;
			}
			dataArray[dataCount] = input;
			dataCount++;
		}

		T pop () {
			if(this->isEmpty() == true){
				std::cerr << "error in Stack: cannot pop when Stack is empty" << std::endl;
//				return NULL;
			}
			T returnValue = this->peek();
			dataCount--;
			return returnValue;
		}

		T peek () {
			return dataArray[dataCount - 1];
		}

		bool empty () {
			return this->isEmpty();
		}

		bool isEmpty () {
			if(dataCount != 0)
				return true;
			return false;
		}
};

#endif /* end STACK_H */
