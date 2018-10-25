/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Filename:    Stack.h
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
				std::string theError = "error in Stack: cannot pop when Stack is empty";
				std::cerr << theError << std::endl;
				throw(theError);
			}
			T returnValue = this->peek();
			dataCount--;
			return returnValue;
		}

		T peek () {
			if(this->isEmpty() == true){
				return NULL;
			}
			return dataArray[dataCount - 1];
		}

		bool isEmpty () {
			return dataCount > 0 ? false : true;
		}
};
#endif /* end STACK_H */
