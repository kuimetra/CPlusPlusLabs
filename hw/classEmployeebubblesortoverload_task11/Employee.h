#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
	string name;
	string surname;
	string patronymic;
	unsigned int work_experience;
	float worked_hours;
	float norm_worked_hours;
	float salary;
public:
	Employee() {}
	Employee(string n, string s, string p, unsigned int we, float wh, float nwh, float sa)
	{
		name = n;
		surname = s;
		patronymic = p;
		work_experience = we;
		worked_hours = wh;
		norm_worked_hours = nwh;
		salary = sa;
	}
	Employee(Employee& c)
	{
		surname = c.surname;
		name = c.name;
		patronymic = c.patronymic;
		work_experience = c.work_experience;
		worked_hours = c.worked_hours;
		norm_worked_hours = c.norm_worked_hours;
		salary = c.salary;
	}
	friend istream& operator>>(istream& in, Employee& s)
	{
		in >> s.surname;
		in >> s.name;
		in >> s.patronymic;
		in >> s.work_experience;
		in >> s.worked_hours;
		in >> s.norm_worked_hours;
		return in;
	}
	friend ostream& operator<<(ostream& out, Employee& s)
	{
		out << s.surname;
		out << s.name;
		out << s.patronymic;
		out << s.work_experience;
		out << s.worked_hours;
		out << s.norm_worked_hours;
		return out;
	}
#pragma region overload
	friend bool operator == (Employee& s1, Employee& s2);
	friend bool operator >(Employee& s1, Employee& s2);
	friend bool operator <(Employee& s1, Employee& s2)
	{
		return s1.salary < s2.salary;
	}
	friend bool operator >=(Employee& s1, Employee& s2);
	friend bool operator <=(Employee& s1, Employee& s2);
#pragma endregion
	friend void output(ostream& out, Employee* s, int n)
	{
		for (int i = 0; i < n; i++)
		{
			out << "Surname, name and patronymic: " << s[i].surname << " " << s[i].name << " " << s[i].patronymic << endl;
			out << "Work experience: " << s[i].work_experience << " years." << endl;
			out << "Worked hours: " << s[i].worked_hours << " hours." << endl;
			out << "Norm of worked hours: " << s[i].norm_worked_hours << " hours." << endl << endl;
		}
	}
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
#pragma endregion
	friend void payroll(ostream& out, Employee* s, int n)
	{
		float* f = new float[n];
		const int salary_per_hour = 56;
		for (int i = 0; i < n; i++)
		{
			double a = 0;
			unsigned int x = s[i].get_worked_hours() * salary_per_hour;
			if ((s[i].get_work_experience() < 10) && (s[i].get_worked_hours() < s[i].get_norm_worked_hours()))
			{
				a = x * 0.8; out << "Dear " << s[i].get_surname() << " " << s[i].get_name()[0] << ". " << s[i].get_patronymic()[0] << ". " << "-20%! because of worked hours : $" << a << endl;
			}
			else if (s[i].get_work_experience() < 10)
			{
				a = x; out << "Dear " << s[i].get_surname() << " " << s[i].get_name()[0] << ". " << s[i].get_patronymic()[0] << ". " << "you have ordinary salary : $" << a << endl;
			}
			if ((s[i].get_work_experience() >= 10 && s[i].get_work_experience() < 20) && (s[i].get_worked_hours() < s[i].get_norm_worked_hours()))
			{
				a = x * 0.88; out << "Dear " << s[i].get_surname() << " " << s[i].get_name()[0] << ". " << s[i].get_patronymic()[0] << ". " << "-12%! because of worked hours, work experience [10;20) : $" << a << endl;
			}
			else if (s[i].get_work_experience() >= 10 && s[i].get_work_experience() < 20)
			{
				a = x * 1.1; out << "Dear " << s[i].get_surname() << " " << s[i].get_name()[0] << ". " << s[i].get_patronymic()[0] << ". " << "+10%! because of work experience [10;20) : $" << a << endl;
			}
			if ((s[i].get_work_experience() >= 20) && (s[i].get_worked_hours() < s[i].get_norm_worked_hours()))
			{
				a = x * 0.96; out << "Dear " << s[i].get_surname() << " " << s[i].get_name()[0] << ". " << s[i].get_patronymic()[0] << ". " << "-4%! because of worked hours, work experience >20 : $" << a << endl;
			}
			else if (s[i].get_work_experience() >= 20)
			{
				a = x * 1.2; out << "Dear " << s[i].get_surname() << " " << s[i].get_name()[0] << ". " << s[i].get_patronymic()[0] << ". " << "+20% because of work experience >20 : $" << a << endl;
			}
			s[i].salary = a;
		}
		out << endl;
	}
	friend void bubblesort(ostream& out, Employee* s, int n)
	{
		Employee t = s[0];
		out << "Sorted by salary : " << endl;
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
		for (int i = 0; i < n; i++)
		{
			out << i + 1 << ". " << s[i].get_surname() << " " << s[i].get_salary() << "$" << endl;
		}
	}
};