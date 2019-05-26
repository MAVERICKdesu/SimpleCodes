#include<iostream>
using namespace std;

template<class T = int>class LinkedList
{
	int number;
	class Node
	{
	public:
		T val;
		Node* next;
		Node()
		{
			next = NULL;
		};
		Node(T x)
		{
			next = NULL;
			val = x;
		};
	};
	Node *head, *crr;
public:
	LinkedList()
	{
		number = 0;
	};
	~LinkedList()
	{
	};
	void insert(T x)
	{
		Node *newNode = new Node(x);
		if (number == 0)
			head = newNode;
		else
		{
			crr = head;
			while (crr->next != NULL)
				crr = crr->next;
			crr->next = newNode;
		}
		++number;
	};
	void del()
	{
		if (number < 2)
		{
			delete head;
			head = NULL;
			--number;
			return;
		}
		for (crr = head; crr->next->next != NULL;)
			crr = crr->next;
		delete crr->next;
		crr->next = NULL;
		--number;
	};
	void prints()
	{
		for (crr = head; crr != NULL; crr = crr->next)
			cout << crr->val << " ";
		cout << endl << number;
	};
};
