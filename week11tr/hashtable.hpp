#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

class HashTable
{
	private:
		int* buckets;
		int size;
		double elementCount;
		int Hash(int value);
		void Resize();
	public:
		HashTable();
		HashTable(int size);
		void Insert(int newValue);
		void Delete(int value);
		int Search(int value);
};

#endif
