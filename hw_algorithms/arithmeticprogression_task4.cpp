#include <iostream>
#include <cmath>
using namespace std;

void main()
{
	int n;
	cout << "Enter amount of elements in arithmetic progression: ";
	cin >> n;
	int* array = new int[n];
	cout << "Enter the elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	cout << endl;
	int a = 0;
	int k = n - 1;
	int* difference = new int[k];
	for (int j = 1; j < n; j++)
	{
		for (int i = j - 1; i < n; i++)
		{
			difference[a] = array[j] - array[i];
			a++;
			break;
		}
	}
	int len = 1, maxlen = 0;
	int begin = 0, end = 0;
	int counter = 1;
	for (int a = 0; a < k; a++)
		if (difference[a] == difference[a + 1])
		{
			len++;
		}
		else
		{
			if (maxlen < len)
			{
				maxlen = len; end = a + 1; begin = end - maxlen;
			}
			len = 1;
		}

	if (maxlen <= len) { maxlen = len; end = n + 1; begin = n - maxlen; }
	cout << "The longest subsequence in arithmetic progression consist of: " << maxlen + 1 << " elements" << endl;
	cout << "It begins with i = " << begin << " and ends with i = " << end << endl;
	cout << "Numbers that form an arithmetic sequence: ";
	for (int i = begin; i <= end; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << endl;
	delete[]array;
	system("pause");
}