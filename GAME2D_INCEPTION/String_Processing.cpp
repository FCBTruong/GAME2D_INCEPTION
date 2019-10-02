#include "String_Processing.h"

std::string IntStr(int x)
{
	std::string str = "";
	if (x == 0) return "0";
	while (x > 0)
	{
		int c = x % 10;
		str = char(c + '0') + str;
		x = x / 10;
	}
	return str;
}