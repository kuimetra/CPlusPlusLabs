#include "list.h"
#include <iostream>
using namespace std;

void main()
{
	List list;
	int n, k;

	if (list.empty()) cout << "List is empty!\n";
	else cout << "List is not empty.\n";

	cout << "Enter amount of numbers in list: ";
	cin >> n;
	if (n == 1) cout << "Enter this number: ";
	else cout << "Enter these numbers: ";
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		list.addtoend(k);
	}
	cout << list;

	List flist(list);

	bool s = true;
	while (s)
	{
		int p;
		cout << "\n1 - sum of the last two elements\n" << "2 - remove value from the list\n" << "3 - add element to the top of the list\n";
		cout << "4 - add to the end of the list\n" << "5 - delete whole list\n" << "I choose : ";

		cin >> p;
		switch (p)
		{
		case 1:
		{
			list.sum(n); break;
		}
		case 2:
		{
			cout << "Value = ";
			cin >> k;
			list.delvalue(k);
			cout << list; break;
		}
		case 3:
		{
			cout << "Element = ";
			cin >> k;
			list.addtobegin(k);
			cout << list; break;
		}
		case 4 :
		{
			cout << "Element = ";
			cin >> k;
			list.addtoend(k);
			cout << list; break;
		}
		case 5 :
		{
			list.dellist();
			cout << "Done!\n" << list; break;
		}
		default:
			cout << "You have not selected any of the suggested options\n"; break;
		}
		cout << "Do you want to continue using menu? (1/0)\n";
		cin >> s;
	}
	
	if (list.empty()) cout << "List is empty!\n";
	else cout << "\nInitial list: " << flist << "Final list: " << list << endl;
	
	system("pause");
}