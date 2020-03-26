#include "hashtable.hpp"


HashTable::HashTable()
{
	buckets = new int[13];
}

HashTable::HashTable(int size)
{
	buckets = new int[size];
}

void HashTable::Insert(int newValue)
{
	int index = Hash(newValue);
	//create code for collision resolution
	buckets[index] = newValue;
}

