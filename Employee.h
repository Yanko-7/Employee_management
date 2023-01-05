#pragma once
#include "Person.h"
#include <iostream>
#include "EmployeePosition.cpp"
using namespace std;
namespace data
{
	class Employee : public Person
	{
	public:
		friend class Manager;
		Employee(string);
		Employee(string id, string name, string city, EmployeePosition position, string manager_id, float salary);
		Employee(string id, string name, float salary);
		Employee(const Employee&);
		friend bool operator<(const Employee&, const Employee&);
		string getCity();
		EmployeePosition getPosition();
		string getStringPosition();
		string getManager_id();
		float getSalary();
	private:
		string city;
		EmployeePosition position;
		string manager_id;
		float salary;
	};
}

