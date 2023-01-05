#include "Person.h"
using namespace data;
string Person::getID()
{
	return id;
}
string Person::getName()
{
	return name;
}
Person::Person(string id) :id(id)
{

}

Person::Person(string id, string name) : id(id), name(name)
{
}
