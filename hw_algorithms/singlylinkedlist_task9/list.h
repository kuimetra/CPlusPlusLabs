#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class List
{
	Node* head;
	Node* back;
public:
	List() : head(0), back(0) {}
	List(const List&); ~List();
	bool empty();
	void addtobegin(int t);
	void addtoend(int t);
	void delvalue(int t);
	void sum(int n);
	void dellist();
	friend ostream& operator<<(ostream&, const List&);
};

List::List(const List& l)
{
	if (!l.head)                 
	{
		head = head->next = back = 0;
		return;
	}

	Node* q = l.head;
	head = new Node;
	head->data = q->data;

	Node* r = head;

	while (q = q->next)
	{
		r->next = new Node;
		r->next->data = q->data;
		r = r->next;
	}
	back = r;
	r->next = 0;
}
List::~List()
{
	if (!head) return;
	Node* q;
	do
	{
		q = head;
		head = head->next;
		delete q;
	} while (head);
}
bool List::empty()
{
	bool t;
	t = (head == 0) && (back == 0);
	return t;
}

void List::addtobegin(int t)
{
	Node* r = new Node;                         
	r->data = t;
	r->next = head;
	if (!head)	              
	{
		back = r;
		back->next = 0;
	}
	head = r;
}
void List::addtoend(int t)
{
	Node* r = new Node;                          
	r->data = t;
	r->next = 0;
	if (back) back->next = r;
	else head = r;
	back = r;
}

void List::delvalue(int t)
{
	if (!head) return;

	Node* q = head;

	while (q->data == t)	                                  
	{
		if (!(head = q->next)) return;
		delete q;
		q = head;
	}

	Node* r, * p = q;
	q = q->next;

	while (q)
	{
		r = q;
		q = q->next;
		bool z;
		if (r->data != t) { z = 1;}
		else { z = 0;}
		if ((r->data == t) && (r->next))
		{
			p->next = r->next;
			delete r;
		}
		else if ((r->data == t) && !(r->next))
		{
			p->next = 0;
			back = p;
			back->next = 0;
			delete r;
		}
		if (z) 
			p = p->next;
	}
}
void List::sum(int n)
{
	if (n <= 0) return;
	Node* a = head;
	int sum = 0, sum1 = 0, m = n - 2;
	if (n == 1) { cout << "There is only one element in the list.\n"; }
	else
	{
		while (a != 0 && n--)
		{
			sum += a->data;
			a = a->next;
		}
		Node* b = head;
		while (b != 0 && m--)
		{
			sum1 += b->data;
			b = b->next;
		}
		cout << "Sum of the last two elements = " << sum - sum1 << endl;
	}
}

void List::dellist()
{
	Node* c = head;
	Node* next;

	while (c != NULL)
	{
		next = c->next;
		free(c);
		c = next;
	}

	head = NULL;
}

ostream& operator<<(ostream& out, const List& l)
{
	if (!l.head)
	{
		return out << "List is empty!" << endl;
	}
	else {
		out << "{ ";
		Node* q = l.head;
		do
		{
			out << q->data << ", ";
		} while (q = q->next);

		out << "\b\b" << " }\n";
	}
	return out;
}