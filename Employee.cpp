#include "Employee.h"
using namespace data;
Employee::Employee(string id) :Person(id)
{
}
Employee::Employee(string id, string name, string city, EmployeePosition position, string manager_id, float salary) : Person(id, name), city(city), salary(salary), position(position), manager_id(manager_id)
{
}
Employee::Employee(string id, string name, float salary): Person(id, name), salary(salary)
{
}
Employee::Employee(const Employee& employee) : Person(employee.id, employee.name), city(employee.city), salary(employee.salary), position(employee.position), manager_id(employee.manager_id)
{

}

string data::Employee::getCity()
{
	return city;
}

EmployeePosition data::Employee::getPosition()
{
	return position;
}

string data::Employee::getStringPosition()
{
	switch (position)
	{
	case data::EmployeePosition::Internship:
		return "Internship";
	case data::EmployeePosition::Ordinary:
		return "Ordinary";
	case data::EmployeePosition::Senior:
		return "Senior";
	default:
		return "";
	}
}

string data::Employee::getManager_id()
{
	return manager_id;
}

float data::Employee::getSalary()
{
	return salary;
}

bool data::operator<(const Employee& e1, const Employee& e2)
{
	return e1.id < e2.id;
}
