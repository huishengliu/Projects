// 31ValidPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

// Clarification questions:
// - is white space character considered?
// - can the string be empty?
// - is it case insensitive?

bool IsValidPalindrome(const std::string& input)
{
	if (input.empty())
	{
		return true;
	}

	int i = 0;
	int j = input.size() - 1;

	while (i <= j)
	{
		while (i < j && !isalpha(input[i]) && !isdigit(input[i])) { ++i; }
		while (i < j && !isalpha(input[j]) && !isdigit(input[j])) { --j; };

		if (tolower(input[i]) == tolower(input[j]))
		{
			++i;
			--j;
		}
		else
		{
			return false;
		}
	}

	return i > j;
}

bool IsValidPalindrome2(const std::string& input)
{
	if (input.empty())
	{
		return true;
	}

	int i = 0;
	int j = input.size() - 1;

	while (i < j)
	{
		if (!isalnum(input[i])) 
		{ 
			++i; 
		}
		else if (!isalnum(input[j])) 
		{ 
			--j; 
		}
		else if (tolower(input[i]) == tolower(input[j]))
		{
			++i;
			--j;
		}
		else
		{
			return false;
		}
	}

	return true;
}

int main()
{
	char* s1 = "A man, a plan, a canal : Panama";
	char* s2 = "race a car";

	std::cout << "space: " << isalpha(' ') << std::endl;

	std::cout << s1 << "  " << IsValidPalindrome2(s1) << std::endl;
	std::cout << s2 << "  " << IsValidPalindrome2(s2) << std::endl;

    return 0;
}

