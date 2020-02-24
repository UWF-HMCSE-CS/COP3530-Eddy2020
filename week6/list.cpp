#include "list.hpp"
#include <iostream>

List::List()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}

void List::prepend(int value)
{
	Node* newNode = new Node(value);
	newNode->setNext(this->head);
	if(this->isEmpty())
	{
		this->tail = newNode;
	}
	this->head = newNode;
	this->length++;
}

void List::append(int value)
{
	if(this->isEmpty())
	{
		this->prepend(value);
		return;
	}
	Node* newNode = new Node(value);
	this->tail->setNext(newNode);
	this->tail = newNode;
	this->length++;
}

void List::insertAt(int position, int value)
{
	if(position < 0 || position > this->getLength())
	{
		return;
	}

	if(position == 0)
	{
		this->prepend(value);
	}

	if(position == this->getLength())
	{
		this->append(value);
	}


	Node* current = this->head;
	while(current != )
	{
		current = current->getNext();
	}
}

int List::getLength()
{
	return this->length;
}

bool List::isEmpty()
{
	return this->length == 0;
}

void List::print()
{
	Node* current =  this->head; 
	while(current != nullptr)
	{
		std::cout << current->getValue() << std::endl;
		current = current->getNext();
	}
}

