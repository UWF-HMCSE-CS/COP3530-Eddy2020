#include <iostream>
#include "node.hpp"
#include "list.hpp"

int main()
{
	Node* n = new Node(5);
	std::cout << n->getValue() << std::endl;
	n->setValue(6);
	std::cout << n->getValue() << std::endl;

	Node* m = new Node(12);
	n->setNext(m);
	std::cout << n->getNext()->getValue() << std::endl;

	List* myList = new List();
	myList->prepend(3);
	myList->prepend(2);
	myList->append(5);
	myList->insertAt(2, 4);
	myList->print();
}
