#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

class List
{
	private:
		Node* head;
		Node* tail;
		int length;
	public:
		List();
		void prepend(int value);
		void print();
		void append(int value);
		bool isEmpty();
		int getLength();
		void insertAt(int position, int value);
		void remove(int value);
};

#endif
