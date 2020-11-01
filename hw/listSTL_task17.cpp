#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> l = { -1, 5, 4, 3, 3, 2, 6, 3, -2, 2 };
	list<int> s(l);
	if (l.empty())
	{
		cout << "The list is empty!" << endl;
		system("pause");
	}
	else
	{
		cout << "Given list for 1st & 2nd task:\n";
		for (int n : l)
		{
			cout << n << " ";
		}
		cout << "\n\n1 - swapping, 2 - deleting ---> ";
		int q;
		cin >> q;
		if (q == 1) 
		{
			auto beg = l.front();
			auto en = l.back();
			l.push_back(beg);
			l.erase(l.begin());
			l.push_front(en);
			list<int>::iterator it = l.end();
			advance(it, -2);
			l.erase(it);
			cout << "\nAfter swapping first and last element:\n";
			for (auto iter = l.begin(); iter != l.end(); iter++)
			{
				cout << *iter << " ";
			}cout << endl;
			cout << "\nEnter 2 - to see deleting too ---> "; cin >> q;
		}
		if (q == 2)
		{
			cout << "\nThe program will delete the following element of element: ";
			int z;
			cin >> z;
			for (auto itr = s.begin(); itr != s.end(); itr++)
			{
				if (*itr == z)
				{
					int t = *itr;
					advance(itr, 1);
					if (t != *itr)
					{
						s.erase(itr); break;
					}
				}
			}
			for (int a : s)
			{
				cout << a << " ";
			}cout << endl;
		}
		system("pause");
	}
}