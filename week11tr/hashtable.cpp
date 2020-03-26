#include "hashtable.hpp"
#include <iostream>

HashTable::HashTable()
{
	buckets = new int[13];
	for(int i = 0; i < 13; ++i)
	{
		buckets[i] = -1;
	}
	this->size = 13;
	this->elementCount = 0;
}

HashTable::HashTable(int size)
{
	buckets = new int[size];
	for(int i = 0; i < size; ++i)
	{
		buckets[i] = -1;
	}
	this->size = 13;
	this->elementCount = 0;
}

int HashTable::Hash(int value)
{
	return value % this->size;
}

void HashTable::Resize()
{
	int newSize = this->size * 2;
	int* temp = this->buckets;
	this->buckets = new int[newSize];
	//set spaces to empty
	
}

void HashTable::Insert(int newValue)
{
	double loadFactor = (this->elementCount + 1) / this->size; 
	if(loadFactor >= 0.5)
		Resize();
	int index = Hash(newValue);
	int bucketsProbed = 0;
	while(bucketsProbed < this->size)
	{
		if(buckets[index] == -1)
		{
			buckets[index] = newValue;
			return;
		}
		
		index = (index + 1) % this->size;
		++bucketsProbed;
	}		
}



