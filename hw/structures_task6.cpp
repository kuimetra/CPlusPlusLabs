#include <iostream>
#include <string>
using namespace std;
struct club
{
	string name;
	int year;
	string city;
};
void input(club& s)
{
	cout << "Name: ";
	cin >> s.name;
	cout << "Year: ";
	cin >> s.year;
	cout << "City: ";
	cin >> s.city;
}
void output(club& s)
{
	cout << s.name << " " << s.year << " " << s.city << endl;
}
void sortbyname(club* c, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (c[j].name > c[j + 1].name)
			{
				club t = c[j];
				c[j] = c[j + 1];
				c[j + 1] = t;
			}
		}
	}
}
club oldest(club* c, int n)
{
	int min = c[0].year;
	club t = c[0];
	for (int i = 0; i < n; i++)
	{
		if (min > c[i].year)
		{
			min = c[i].year;
			t = c[i];
		}
	}
	return t;
}
int main()
{
	int n;
	cout << "Enter the number of clubs: ";
	cin >> n;
	club* s = new club[n];
	for (int i = 0; i < n; i++)
	{
		input(s[i]);
	}
	cout << endl;
	cout << "Info:\n";
	for (int i = 0; i < n; i++)
	{
		output(s[i]);
	}
	cout << endl;

	sortbyname(s, n);
	cout << "Sorted by club name:\n";
	for (int i = 0; i < n; i++)
	{
		output(s[i]);
	}
	cout << endl;
	club min;
	min = oldest(s, n);
	cout << "The oldest club is:\n";
	output(min);

	system("pause");
	return 0;
}