#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

class HashTable
{
	private:
		int* buckets;
		int Hash(int value);
		void Resize();		
	public:
		HashTable();
		HashTable(int size);
		void Insert(int newValue);
		void Remove(int newValue);
		int GetSize();
		int Search(int searchValue);
};

#endif
