#include "User.h"
#include "DiFactory.h"


data::User::User(string id, string password) :id(id), password(password)
{
}

bool data::User::Login()
{
	User* u = DiFactory::getInstance().getUserDAO().findData(id);
	if (u != NULL && u->password == password)
	{
		Manager::Init(id, "def");
		return true;
	}
	return false;
}

bool data::User::Register()
{
	User u(id, password);
	if (DiFactory::getInstance().getUserDAO().findData(id) == NULL)
	{
		DiFactory::getInstance().getUserDAO().saveData(u);
		return true;
	}
	return false;
}
