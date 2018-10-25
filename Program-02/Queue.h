/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Filename:    Queue.h
 *  Title:       CSC1310 - Program - 02
 *  Author(s):   Rus Hoffman
 *  Created On:  September 26, 2018
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
#if !defined(QUEUE_H)
#define QUEUE_H

#include <iomanip>
#include <iostream>
#include <list>
#include <string>

template<class T> class MyQueue {
	private:
		std::list<T> dataListList;
		size_t dataCount;

	public:
		MyQueue () {
			dataCount = 0;
		}

		~MyQueue () {
			dataCount = 0;
		}

		void push (T input) {
			this->push_back(input);
		}

		void enqueue (T input) {
			this->push_back(input);
		}

		void push_back (T input) {
			dataListList.push_back(input);
			dataCount++;
		}

		T dequeue () {
			return this->pop_front();
		}
		T pop () {
			return this->pop_front();
		}

		T pop_front () {
			T returnData = dataListList.front();
			dataListList.pop_front();
			dataCount--;
			return returnData;
		}

		bool isEmpty () {
			return dataCount > 0 ? false : true;
		}

		void display (bool shouldAddSpace = false) {
			std::cout << std::setw(0) << std::setfill(' ');
			for (std::list<char>::const_iterator dataListItr = dataListList.begin(); dataListItr != dataListList.end(); dataListItr++) {
				std::cout << *dataListItr;
				if(shouldAddSpace == true) {
					std::cout << " ";
				}
			}
			std::cout << std::flush;
		}
};
#endif /* QUEUE_H */
