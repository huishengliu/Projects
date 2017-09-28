// 33StringToInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "assert.h"

int GetSign(const char *input, const char *&value)
{
	int sign = 1;
	const char* p = input;
	if (*p == '-')
	{
		sign = -1;
		++p;
	}
	else if (*p == '+')
	{
		++p;
	}

	value = p;
	return sign;
}


// decimal only
bool StringToInteger(const char *input, int& value)
{
	if (!input || !*input)
		return false;

	const char* p = nullptr;
	int sign = GetSign(input, p);

	value = 0;
	while (*p && *p >= '0' && *p <= '9')
	{
		value *= 10;
		value += *p - '0';
		++p;
	}

	if (*p)
	{
		return false;
	}

	value *= sign;

	return true;
}

bool IsValidDigit(char c, int base)
{
	if (base == 10)
	{
		return c >= '0' && c <= '9';
	}
	else if (base == 16)
	{
		return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
	}
	else
	{
		return false;
	}
}

int CtoD(char c, int base)
{
	if (base == 10)
	{
		return c - '0';
	}
	else {
		assert(base == 16);
		if (c >= '0' && c <= '9')
		{
			return c - '0';
		}
		else if (c >= 'a' && c <= 'f')
		{
			return c - 'a' + 10;
		}
		else
		{
			return c - 'A' + 10;
		}
	}
}

// with variable base
bool StringToInteger(const char *input, int base, int& value)
{
	if (!input || !*input)
		return false;

	const char* p = nullptr;
	int sign = GetSign(input, p);

	value = 0;
	while (*p && IsValidDigit(*p, base))  // need to check min/max
	{
		value *= base;
		value += CtoD(*p, base);
		++p;
	}

	return *p == '\0';  // or ' ', etc
}

// dec only
int StringToInteger(const char *input)
{
	if (!input || !*input)
	{
		return 0;
	}

	const char *p = input;
	while (*p && isspace(*p)) ++p;

	int sign = 1;
	if (*p && *p == '-') sign = -1, ++p;

	int value = 0;
	bool overflow = false;
	while (!overflow && *p && *p >= '0' and *p <= '9')
	{
		if (value < INT_MAX / 10)
		{
			value *= 10;
			if (value < INT_MAX - (*p - '0'))
				value += *p - '0';
			else
				overflow = true;
		}
		else
			overflow = true;
	}

	if (sign == -1 && value == INT_MAX)
	{
		overflow = true;
		value = INT_MIN;
	}

	return value;
}

int main()
{
	char* n1 = "357";
	int value = 0;
	bool f = StringToInteger(n1, value);
	std::cout << f << " " << value << std::endl;

	n1 = "-234";
	f = StringToInteger(n1, value);
	std::cout << f << " " << value << std::endl;

	n1 = "+3";
	f = StringToInteger(n1, value);
	std::cout << f << " " << value << std::endl;

	n1 = "-23abc";
	f = StringToInteger(n1, value);
	std::cout << f << std::endl;

	n1 = "-23abc";
	f = StringToInteger(n1, 16, value);
	std::cout << f << " " << value << std::endl;

    return 0;
}

