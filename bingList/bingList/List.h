#pragma once
#include <system_error>

class List
{
public:
	List()
	{
		init();
	}
	~List()
	{
		clear();
		delete head;
		delete tail;
	}
	class iterator
	{
	public:

	};
	struct Node
	{
	public:
		int data;
		Node * prev;
		Node *next;
		Node()
		{
			prev = nullptr;
			next = nullptr;
			data = 0;
		};
		Node(int d, Node * p = nullptr, Node * n = nullptr) 
		: data{ d }, prev{ p }, next{ n } {}
	};
	void init()
	{
		listsize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
	int size(); // returns the number of elements in the list.
	void clear() ; //removes all elements from the list.
	bool empty() ; //returns true if the list contains no elements, and false otherwise.
	void push_back(List Object & x); //adds x to the end of the list.
	void pop_back(); //removes the object at the end of the list.
	void push_front(List Object & x) ; //adds x to the front of the list.
	void pop_front() ; //removes the object at the front of the list.
	Object & back() ; //returns the reference to the element at the end of the list.
	Object & front() ; //returns the reference to the element at the front of the list.
	List(const List & rhs) ; //copy constructor
	List & operator= (const List & rhs) ; //copy assignment constructor	
	iterator begin() ; //returns an iterator that represents the first node in the list.
	iterator end() ; //returns the tail node.
	iterator insert(iterator itr, const Object & x) ; //insert an element with value x before the element pointed to by itr.
	iterator erase(iterator itr) ; //remove element pointed to by itr
	iterator erase(iterator from, iterator to) ; //remove elements from “from” to “to”

private:
	int listsize;
	Node *head;
	Node *tail;
};

