#include<iostream>
#include<iterator>
#include<fstream>
#include<numeric>
#include<string>
#include<set>
using namespace std;

class Employee
{
public:
	string surname;
	string name;
	string patronymic;
	unsigned int work_experience;
	float worked_hours;
	float norm_worked_hours;
#pragma region constructors
	Employee() {}
	Employee(string s, string n, string p, unsigned int we, float wh, float nwh)
	{
		surname = s;
		name = n;
		patronymic = p;
		work_experience = we;
		worked_hours = wh;
		norm_worked_hours = nwh;
	}
#pragma endregion 
	void input(istream& in)
	{
		in >> surname >> name >> patronymic >> work_experience >> worked_hours >> norm_worked_hours;
	}
	string get_surname() { return surname; }
	string get_patronymic() { return patronymic; }
	unsigned int get_work_experience() { return work_experience; }
	float get_worked_hours() { return worked_hours; }
	float get_norm_worked_hours() { return norm_worked_hours; }

	friend bool operator < (const Employee& s1, const Employee& s2)
	{
		return s1.surname < s2.surname;
	}
	friend ostream& operator<<(ostream& out, const Employee& s);
	friend void uppercase(Employee& s);
};
ostream& operator<<(ostream& out, const Employee& s)
{
	out << s.surname << " " << s.name << " " << s.patronymic << " " << s.work_experience << " years, " << s.worked_hours << " hours from " << s.norm_worked_hours;
	return out;
}

void uppercase(Employee& s)
{
	char letter;
	for (int i = 0; i < s.surname.size(); i++)
	{
		letter = (char)s.surname[i];
		if (letter >= 'a' && letter <= 'z')
		{
			letter = letter - 32;
			s.surname[i] = (char)letter;
		}
	}
}

int main()
{
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Error! File not found!" << endl;
		in.close();
		system("pause");
		return 1;
	}
	ofstream out("out.txt");
	multiset<Employee>m;
	int n;
	in >> n;
	Employee* s = new Employee[n];
	for (int i = 0; i < n; i++)
	{
		s[i].input(in);
		m.insert(s[i]);
	}
	int c = 1;
	while (c == 1)
	{
		cout << "Menu :\n1 - show info(iter)\n2 - show info(copy)\n3 - convert surname to upper case\n4 - sum of worked hours" << endl;
		int t;
		cin >> t;
		switch (t)
		{
		case 1:
		{
			out << "Iter info:\n";
			for (auto iter = m.begin(); iter != m.end(); iter++)
			{
				cout << *iter << endl;
				out << *iter << endl;
			}
			out << endl;
		}break;
		case 2:
		{
			out << "Copy info:\n";
			for (auto& it : m)
			{
				cout << it << endl;
				out << it << endl;
			}
			out << endl;
		}break;
		case 3:
		{
			m.clear();
			out << "Uppercase:\n";
			for (int i = 0; i < n; i++)
			{
				uppercase(s[i]);
				m.insert(s[i]);
			}
			for (auto& it : m)
			{
				cout << it << endl;
				out << it << endl;
			}
			out << endl;
		}break;
		case 4:
		{
			int sum = accumulate(begin(m), end(m), 0, [](float s, Employee s1) {return s + s1.get_worked_hours(); });
			cout << "sum = " << sum << " hours\n";
			out << "sum of worked hours = " << sum << endl;
		}break;
		default:
			break;
		}
		cout << "\nEnter 1 if you want to continue -> ";
		cin >> c;
		switch (c)
		{
		case 1:
			c = true;
			break;
		default:
			c = false;
			break;
		}
		cout << endl;
	}
	out.close();
	delete[] s;
	system("pause");
}