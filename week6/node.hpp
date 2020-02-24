#ifndef NODE_HPP
#define NODE_HPP

class Node 
{
	private:
		int value;
		Node* next;
	public:
		Node(int value);
		int getValue();
		void setValue(int value);
		Node* getNext();
		void setNext(Node* next);	
};

#endif
