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
		return;
	}

	if(position == this->getLength())
	{
		this->append(value);
		return;
	}


	Node* current = this->head;
	int currentPosition = 0;
	while(currentPosition != position - 1)
	{
		currentPosition++;
		current = current->getNext();
	}

	Node* newNode = new Node(value);
	newNode->setNext(current->getNext());
	current->setNext(newNode);

	this->length++;
}

void List::remove(int value)
{
	if(this->isEmpty())
		return;

	Node* nodeToRemove;
	if(this->head->getValue() == value)
	{
		nodeToRemove = this->head;
		this->head = this->head->getNext();
	}
	else
	{
		Node* current = this->head;
		if(current->getNext() == nullptr)
			return;

		while(current->getNext() != nullptr && current->getNext()->getValue() != value)
		{
			current = current->getNext();
		}
			
		nodeToRemove = current->getNext();
		current->setNext(nodeToRemove->getNext());
	}
	delete nodeToRemove;
	this->length--;
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

