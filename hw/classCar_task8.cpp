#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
	string name;
	int year;
	double price;

public:
	Car() {}
	Car(string n, int y, double p)
	{
		name = n;
		year = y;
		price = p;
	}
	Car(Car& c)
	{
		name = c.name;
		year = c.year;
		price = c.price;
	}
	void output(Car& c)
	{
		cout << "Name: " << c.name << "\tYear of production: " << c.year << "\tPrice: " << c.price << endl;
	}
	void input(Car& c)
	{
		cout << "Name: ";
		cin >> c.name;
		cout << "Year of production: ";
		cin >> c.year;
		cout << "Price: ";
		cin >> c.price;
	}

	string get_name()
	{
		return name;
	}
	int get_year()
	{
		return year;
	}
	float get_price()
	{
		return price;
	}
	void set_name(string n)
	{
		name = n;
	}
	void set_amount(int y)
	{
		year = y;
	}
	void set_average(double p)
	{
		price = p;
	}

	void century(Car& c)
	{
		if (c.year >= 1801 && c.year <= 1900)
		{
			cout << " 19 century" << endl;
		}
		else if (c.year >= 1901 && c.year <= 2000)
		{
			cout << " 20 century" << endl;
		}
		else if (c.year >= 2001 && c.year <= 2100)
		{
			cout << " 21 century" << endl;
		}
	}

	Car the_most_expensive(Car* c, int n)
	{
		int max = c[0].price;
		Car t = c[0];
		for (int i = 0; i < n; i++)
		{
			if (max < c[i].price)
			{
				max = c[i].price;
				t = c[i];
			}
		}
		cout << "The most expensive car is " << t.name << " that cost " << max << endl;
		return t;
	}
};
int main()
{
	int n;
	cout << "Enter amount of cars: ";
	cin >> n;
	Car* s = new Car[n];
	for (int i = 0; i < n; i++)
	{
		s[i].input(s[i]);
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		s[i].output(s[i]);
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Car number " << i + 1 << " is produced in";
		s[i].century(s[i]);
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		s[i].the_most_expensive(s, n);
		break;
	}
	cout << endl;
	system("pause");
	return 0;
}