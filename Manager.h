#pragma once
#include "Person.h"
#include "Employee.h"
#include <set>
#include <map>
#include "EmployeePosition.cpp"
namespace data
{
	class Manager : public Person
	{
	public:
		Manager(string, string);
		Employee SearchEmployee(string);
		set<Employee> SearchEmployee(EmployeePosition);
		set<Employee> SearchEmployee();
		bool ChangeEmployeeSalary(string, float);
		bool ChangeEmployeeSalary(set<string>, float);
		bool ChangeEmployeeManager(string id, string manager_id);
		void SetEmployeeInfo(string id, string name, string city, EmployeePosition position);
		Manager& operator+(const Employee&);
		Manager& operator-(const Employee&);
		static Manager* getInstance();
		static void Init(string id, string name);


	private:
		map<string, Employee> employeeMap;
		static Manager* instance;


	};
}

