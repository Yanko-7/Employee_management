#pragma once
#include <iostream>
using namespace std;
namespace data
{
	class User
	{
	public:
		User(string id, string password);
		bool Login();
		bool Register();
		string password;
		string id;
	};
}

