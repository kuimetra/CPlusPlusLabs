#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void add1(Node*& begq1, Node*& endq1, int d)
{
	Node* c = new Node;
	c->data = d;
	c->next = 0;
	if (endq1 == 0) begq1 = c;
	else endq1->next = c;
	endq1 = c;
}
void add2(Node*& begq2, Node*& endq2, int d)
{
	Node* c = new Node;
	c->data = d;
	c->next = 0;
	if (endq2 == 0) begq2 = c;
	else endq2->next = c;
	endq2 = c;
}
void add3(Node*& begq3, Node*& endq3, int d)
{
	Node* c = new Node;
	c->data = d;
	c->next = 0;
	if (endq3 == 0) begq3 = c;
	else endq3->next = c;
	endq3 = c;
}
void add4(Node*& begq4, Node*& endq4, int d)
{
	Node* c = new Node;
	c->data = d;
	c->next = 0;
	if (endq4 == 0) begq4 = c;
	else endq4->next = c;
	endq4 = c;
}

void main()
{
	Node* begq1 = 0;
	Node* endq1 = 0;
	Node* begq2 = 0;
	Node* endq2 = 0;
	Node* begq3 = 0;
	Node* endq3 = 0;
	Node* begq4 = 0;
	Node* endq4 = 0;
	int n;
	cout << "Enter amount of people in queue : ";
	cin >> n;
	int* h = new int[n];
	int* m = new int[n];
	int* l = new int[n]; 
	int* d = new int[n];  
	int* t = new int[n];  
	int* eh = new int[n]; 
	int* em = new int[n]; 
	char ch;
	cout << "\nEnter info about arrival and service time\nin this way -> hours:minutes service time\n";
	for (int i = 0; i < n; i++)
	{
		cin >> h[i] >> ch >> m[i] >> l[i];
	}
	for (int i = 0; i < n; i++)
	{
		t[i] = h[i] * 60 + m[i];
		d[i] = t[i] + l[i];
		eh[i] = d[i] / 60;
		em[i] = d[i] % 60;
	}
	add1(begq1, endq1, 0);
	add2(begq2, endq2, 0);
	add3(begq3, endq3, 0);
	add4(begq4, endq4, 0);
	cout << "\nPersonal number. Ticket window number. Arrival time. Service time. End of service.\n";
	for (int i = 0; i < n; i++)
	{
		if (t[i] >= (endq1->data))
		{
			add1(begq1, endq1, d[i]);
			cout << i + 1 << "\t~ 1 ~" << "\t" << h[i] << ':' << m[i] << "\t" << l[i] << " min.\t" << eh[i] << ":" << em[i] << endl;
		}
		else if (t[i] >= (endq2->data))
		{
			add2(begq2, endq2, d[i]);
			cout << i + 1 << "\t~ 2 ~" << "\t" << h[i] << ':' << m[i] << "\t" << l[i] << " min.\t" << eh[i] << ":" << em[i] << endl;
		}
		else if (t[i] >= (endq3->data))
		{
			add3(begq3, endq3, d[i]);
			cout << i + 1 << "\t~ 3 ~" << "\t" << h[i] << ':' << m[i] << "\t" << l[i] << " min.\t" << eh[i] << ":" << em[i] << endl;
		}
		else if (t[i] >= (endq4->data))
		{
			add4(begq4, endq4, d[i]);
			cout << i + 1 << "\t~ 4 ~" << "\t" << h[i] << ':' << m[i] << "\t" << l[i] << " min.\t" << eh[i] << ":" << em[i] << endl;
		}
	}cout << endl;
	system("pause");
}