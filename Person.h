#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace data
{
	class Person
	{
	public:
		Person(string);
		Person(string, string);
		string getID();
		string getName();
	protected:
		string id;
		string name;
	private:

	};
}