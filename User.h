#pragma once
#include <iostream>
using namespace std;
namespace data
{
	class User
	{
	public:
		User(string id, string password);
		bool Login(string id, string password);
		bool Register(string id, string password);
		string password;
		string id;
	};
}

