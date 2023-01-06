#pragma once
#include <string>
namespace data
{
	enum class EmployeePosition
	{
		All = 0,
		Internship,
		Ordinary,
		Senior
	};
	static const std::string PosString[] = { "All","Internship","Ordinary","Senior" };
}
