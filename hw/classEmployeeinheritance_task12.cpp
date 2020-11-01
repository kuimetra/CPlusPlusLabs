#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Employee
{
protected:
	string name;
	string surname;
	string patronymic;
	unsigned int work_experience;
	float worked_hours;
	float norm_worked_hours;
	float salary;
	string reason;
#pragma region constructors
public:
	Employee() {}
	Employee(string n, string s, string p, unsigned int we, float wh, float nwh, float sa, string r)
	{
		surname = s;
		name = n;
		patronymic = p;
		work_experience = we;
		worked_hours = wh;
		norm_worked_hours = nwh;
		salary = sa;
		reason = r;
	}
	Employee(Employee& s)
	{
		surname = s.surname;
		name = s.name;
		patronymic = s.patronymic;
		work_experience = s.work_experience;
		worked_hours = s.worked_hours;
		norm_worked_hours = s.norm_worked_hours;
		salary = s.salary;
		reason = s.reason;
	}
#pragma endregion 
#pragma region get&set
	string get_name()
	{
		return name;
	}
	string get_surname()
	{
		return surname;
	}
	string get_patronymic()
	{
		return patronymic;
	}
	unsigned int get_work_experience()
	{
		return work_experience;
	}
	float get_worked_hours()
	{
		return worked_hours;
	}
	float get_norm_worked_hours()
	{
		return norm_worked_hours;
	}
	float get_salary()
	{
		return salary;
	}
	string get_reason()
	{
		return reason;
	}
	void set_name(string n)
	{
		name = n;
	}
	void set_surname(string s)
	{
		surname = s;
	}
	void set_patronymic(string p)
	{
		patronymic = p;
	}
	void set_work_experience(unsigned int we)
	{
		work_experience = we;
	}
	void set_worked_hours(float wh)
	{
		worked_hours = wh;
	}
	void set_norm_worked_hours(float nwh)
	{
		norm_worked_hours = nwh;
	}
	void set_salary(float sa)
	{
		salary = sa;
	}
	void set_salary(string r)
	{
		reason = r;
	}
#pragma endregion
	virtual void input(istream& in)
	{
		in >> surname >> name >> patronymic >> work_experience >> worked_hours >> norm_worked_hours;
	}
	virtual void output(ostream& out)
	{
		out << surname << endl << name << endl << patronymic << endl << work_experience << endl << worked_hours << endl << norm_worked_hours;
	}
	virtual void show()
	{
		cout << "Surname: " << surname << endl << "Name: " << name << endl << "Patronymic: " << patronymic << endl << "Work experience: " << work_experience << endl << "Worked hours: " << worked_hours << endl << "Norm of worked hours: " << norm_worked_hours << endl << endl;
	}
	virtual float payroll()
	{
		const int salary_per_hour = 56;
		unsigned int x = worked_hours * salary_per_hour; //ordinary salary
		if ((work_experience < 10) && (worked_hours < norm_worked_hours))
		{
			salary = x * 0.8;
		}
		else if (work_experience < 10)
		{
			salary = x;
		}
		if ((work_experience >= 10 && work_experience < 20) && (worked_hours < norm_worked_hours))
		{
			salary = x * 0.88;
		}
		else if (work_experience >= 10 && work_experience < 20)
		{
			salary = x * 1.1;
		}
		if ((work_experience >= 20) && (worked_hours < norm_worked_hours))
		{
			salary = x * 0.96;
		}
		else if (work_experience >= 20)
		{
			salary = x * 1.2;
		}
		return salary;
	}
	virtual string payroll_reason()
	{
		if ((work_experience < 10) && (worked_hours < norm_worked_hours))
		{
			reason = "-20%! because of worked hours : $";
		}
		else if (work_experience < 10)
		{
			reason = "you have ordinary salary : $";
		}
		if ((work_experience >= 10 && work_experience < 20) && (worked_hours < norm_worked_hours))
		{
			reason = "-12%! because of worked hours and work experience [10;20) : $";
		}
		else if (work_experience >= 10 && work_experience < 20)
		{
			reason = "+10%! because of work experience [10, 20) : $";
		}
		if ((work_experience >= 20) && (worked_hours < norm_worked_hours))
		{
			reason = "-4%! because of worked hours and work experience >20 : $";
		}
		else if (work_experience >= 20)
		{
			reason = "+20%! because of work experience >20 : $";
		}
		return reason;
	}
#pragma region overload
	bool operator > (const Employee& other)
	{
		return this->salary > other.salary;
	}
	bool operator < (const Employee& other)
	{
		return this->salary < other.salary;
	}
	bool operator >= (const Employee& other)
	{
		return this->salary >= other.salary;
	}
	bool operator <= (const Employee& other)
	{
		return this->salary <= other.salary;
	}
	bool operator == (const Employee& other)
	{
		return this->salary == other.salary;
	}
	bool operator != (const Employee& other)
	{
		return !(this->salary == other.salary);
	}
	Employee& operator =(Employee& s)
	{
		surname = s.surname;
		name = s.name;
		patronymic = s.patronymic;
		work_experience = s.work_experience;
		worked_hours = s.worked_hours;
		norm_worked_hours = s.norm_worked_hours;
		return *this;
	}
#pragma endregion
	friend ostream& operator << (ostream& out, Employee& s);
	friend istream& operator >> (istream& in, Employee& s);
	friend void bubblesort(ostream& out, Employee* s, int n);
};
void bubblesort(ostream& out, Employee* s, int n)
{
	Employee t = s[0];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (s[j] < s[j + 1])
			{
				Employee t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
		}
	}
	out << "Sorted by name: " << endl;
	for (int i = 0; i < n; i++)
	{
		out << i + 1 << ". " << s[i].get_surname() << " " << s[i].get_name()[0] << ". " << s[i].get_patronymic()[0] << ". " << s[i].get_salary() << "$" << endl;
	}
}

class Junior : public Employee
{
protected:
	int level;
#pragma region constructors
public:
	Junior() { level = 0; }
	Junior(string n, string s, string p, unsigned int we, float wh, float nwh, float sa, string r, int l) : Employee(n, s, p, we, wh, nwh, sa, r)
	{
		level = l;
	}
	Junior(Junior& s) : Employee(s)
	{
		level = s.level;
	}
#pragma endregion 
#pragma region get&set
	int get_level()
	{
		return level;
	}
	void set_level(int l)
	{
		level = l;
	}
#pragma endregion 
	void input(istream& in) override
	{
		in >> surname >> name >> patronymic >> work_experience >> worked_hours >> norm_worked_hours;
	}
	void output(ostream& out) override
	{
		out << surname << endl << name << endl << patronymic << endl << work_experience << endl << worked_hours << endl << norm_worked_hours;
	}
	void show() override
	{
		cout << "Surname : " << surname << endl << "Name : " << name << endl << "Patronymic : " << patronymic << endl << "Work experience : " << work_experience << endl << "Worked hours : " << worked_hours << endl << "Norm of worked hours : " << norm_worked_hours << endl << endl;
	}

	int level_calculation()
	{
		level = work_experience / 10;
		return level;
	}
	float payroll() override
	{
		int premiuml = level_calculation() * 18;
		const int salary_per_hour = 56;
		unsigned int x = worked_hours * salary_per_hour;
		if ((work_experience < 10) && (worked_hours < norm_worked_hours))
		{
			salary = (x * 0.8) + premiuml;
		}
		else if (work_experience < 10)
		{
			salary = x + premiuml;
		}
		if ((work_experience >= 10 && work_experience < 20) && (worked_hours < norm_worked_hours))
		{
			salary = (x * 0.88) + premiuml;
		}
		else if (work_experience >= 10 && work_experience < 20)
		{
			salary = (x * 1.1) + premiuml;
		}
		if ((work_experience >= 20) && (worked_hours < norm_worked_hours))
		{
			salary = (x * 0.96) + premiuml;
		}
		else if (work_experience >= 20)
		{
			salary = (x * 1.2) + premiuml;
		}
		return salary;
	}
	string payroll_reason() override
	{
		if ((work_experience < 10) && (worked_hours < norm_worked_hours))
		{
			reason = "-20%! because of worked hours";
		}
		else if (work_experience < 10)
		{
			reason = "you have ordinary salary";
		}
		if ((work_experience >= 10 && work_experience < 20) && (worked_hours < norm_worked_hours))
		{
			reason = "-12%! because of worked hours and work experience [10;20) + premium";
		}
		else if (work_experience >= 10 && work_experience < 20)
		{
			reason = "+10%! because of work experience [10, 20) + premium";
		}
		if ((work_experience >= 20) && (worked_hours < norm_worked_hours))
		{
			reason = "-4%! because of worked hours and work experience >=20 + premium";
		}
		else if (work_experience >= 20)
		{
			reason = "+20%! because of work experience >=20 + premium";
		}
		return reason;
	}

	friend ostream& operator << (ostream& out, Junior& s);
	friend istream& operator >> (istream& in, Junior& s);
};
ostream& operator << (ostream& out, Junior& s)
{
	out << "Junior info." << endl << "Surname, name and patronymic: " << s.surname << " " << s.name << " " << s.patronymic << endl << "Work experience: " << s.work_experience << " years" << endl << "Worked hours: " << s.worked_hours << " hours" << endl << "Norm of worked hours: " << s.norm_worked_hours << " hours" << endl << endl;
	return out;
}
istream& operator >> (istream& in, Junior& s)
{
	in >> s.surname >> s.name >> s.patronymic >> s.work_experience >> s.worked_hours >> s.norm_worked_hours;
	return in;
}

class Head : public Employee
{
protected:
	unsigned int amount_of_juniors;
#pragma region constructors
public:
	Head() {}
	Head(string n, string s, string p, unsigned int we, float wh, float nwh, float sa, string r, unsigned int aoj) : Employee(n, s, p, we, wh, nwh, sa, r)
	{
		amount_of_juniors = aoj;
	}
	Head(Head& s) : Employee(s)
	{
		amount_of_juniors = s.amount_of_juniors;
	}
#pragma endregion
#pragma region get&set
	unsigned int get_amount_of_juniors()
	{
		return amount_of_juniors;
	}
	void set_amount_of_juniors(unsigned int aoj)
	{
		amount_of_juniors = aoj;
	}
#pragma endregion 
	void input(istream& in) override
	{
		in >> surname >> name >> patronymic >> work_experience >> worked_hours >> norm_worked_hours >> amount_of_juniors;
	}
	void output(ostream& out) override
	{
		out << surname << endl << name << endl << patronymic << endl << work_experience << endl << worked_hours << endl << norm_worked_hours << endl << amount_of_juniors;
	}
	void show() override
	{
		cout << "Surname: " << surname << endl << "Name: " << name << endl << "Patronymic: " << patronymic << endl << "Work experience: " << work_experience << endl << "Worked hours: " << worked_hours << endl << "Norm of worked hours: " << norm_worked_hours << endl << "Amount of juniors: " << amount_of_juniors << endl << endl;
	}
	float payroll() override
	{
		int premiumj = amount_of_juniors * 7;
		const int salary_per_hour = 65;
		unsigned int x = worked_hours * salary_per_hour; //ordinary salary
		if ((work_experience < 10) && (worked_hours < norm_worked_hours))
		{
			salary = (x * 0.8) + premiumj;
		}
		else if (work_experience < 10)
		{
			salary = x + premiumj;
		}
		if ((work_experience >= 10 && work_experience < 20) && (worked_hours < norm_worked_hours))
		{
			salary = (x * 0.88) + premiumj;
		}
		else if (work_experience >= 10 && work_experience < 20)
		{
			salary = (x * 1.1) + premiumj;
		}
		if ((work_experience >= 20) && (worked_hours < norm_worked_hours))
		{
			salary = (x * 0.96) + premiumj;
		}
		else if (work_experience >= 20)
		{
			salary = (x * 1.2) + premiumj;
		}
		return salary;
	}
	string payroll_reason() override
	{
		if ((work_experience < 10) && (worked_hours < norm_worked_hours))
		{
			reason = "-20%! because of worked hours";
		}
		else if (work_experience < 10)
		{
			reason = "you have ordinary salary";
		}
		if ((work_experience >= 10 && work_experience < 20) && (worked_hours < norm_worked_hours))
		{
			reason = "-12%! because of worked hours and work experience [10;20)";
		}
		else if (work_experience >= 10 && work_experience < 20)
		{
			reason = "+10%! because of work experience [10, 20)";
		}
		if ((work_experience >= 20) && (worked_hours < norm_worked_hours))
		{
			reason = "-4%! because of worked hours and work experience >=20";
		}
		else if (work_experience >= 20)
		{
			reason = "+20%! because of work experience >=20";
		}
		return reason;
	}

	friend ostream& operator << (ostream& out, Head& s);
	friend istream& operator >> (istream& in, Head& s);
};
ostream& operator << (ostream& out, Head& s)
{
	out << "Head info." << endl << "Surname, name and patronymic: " << s.surname << " " << s.name << " " << s.patronymic << endl << "Work experience: " << s.work_experience << " years" << endl << "Worked hours: " << s.worked_hours << " hours" << endl << "Norm of worked hours: " << s.norm_worked_hours << " hours" << endl << "Amount of juniors: " << s.amount_of_juniors << endl << endl;
	return out;
}
istream& operator >> (istream& in, Head& s)
{
	in >> s.surname >> s.name >> s.patronymic >> s.work_experience >> s.worked_hours >> s.norm_worked_hours >> s.amount_of_juniors;
	return in;
}

void main()
{
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Error! File not found!" << endl;
		system("pause");
		in.close();
	}
	ofstream out("out.txt");
	int n;
	in >> n;
	Junior* a = new Junior[n];
	for (int i = 0; i < n; i++)
		in >> a[i];
	for (int i = 0; i < n; i++)
	{
		out << a[i] << "Dear " << a[i].get_surname() << " " << a[i].get_name()[0] << ". " << a[i].get_patronymic()[0] << ". " << endl << "Your salary: $" << a[i].payroll() << " (" << a[i].payroll_reason();
		if (a[i].get_work_experience() < 10)
			out << ")" << endl;
		else if (a[i].get_work_experience() >= 10)
			out << " $" << a[i].level_calculation() * 18 << ")" << endl;
		out << "________________________________________________________________________________________________" << endl;
	}
	int k;
	in >> k;
	Head* b = new Head[k];
	for (int i = 0; i < k; i++)
		in >> b[i];
	for (int i = 0; i < k; i++)
	{
		out << b[i] << "Dear " << b[i].get_surname() << " " << b[i].get_name()[0] << ". " << b[i].get_patronymic()[0] << ". " << endl << "Your salary: $" << b[i].payroll() << " (" << b[i].payroll_reason();
		if (b[i].get_amount_of_juniors() == 0)
			out << ")" << endl;
		if (b[i].get_amount_of_juniors() != 0)
			out << " + premium $" << b[i].get_amount_of_juniors() * 7 << ")" << endl;
		out << "________________________________________________________________________________________________" << endl;
	}
	in.close();
	cout << "Look for the file with the name out.txt :)" << endl;
	system("pause");
}