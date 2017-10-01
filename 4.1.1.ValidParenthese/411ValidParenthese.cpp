// 411ValidParenthese.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stack>

// Clarification Questions:
// - assume not empty
// - can be nested

bool IsValidParenthese(const std::string& input)
{
	std::stack<char> mystack;
	for (auto it = input.begin(); it < input.end(); ++it)
	{
		switch (*it)
		{
		case '(':
		case '[':
			mystack.push(*it);
			break;
		case ')':
			if (mystack.top() != '(')
			{
				return false;
			}
			mystack.pop();
			break;
		case ']':
			if (mystack.top() != ']')
			{
				return false;
			}
			mystack.pop();
			break;
		default:
			return false;
		}
	}

	return mystack.empty();
}

char MatchingParenthese(char c)
{
	return c == ')' ? '(' : (c == ']' ? '[' : '}');
}

bool IsValidParenthese2(const std::string& input)
{
	std::stack<char> mystack;
	for (auto it = input.begin(); it < input.end(); ++it)
	{
		switch (*it)
		{
		case '(':
		case '[':
		case '{':
			mystack.push(*it);
			break;
		case ')':
		case ']':
		case '}':
			if (mystack.top() != MatchingParenthese(*it))
			{
				return false;
			}
			mystack.pop();
			break;
		default:
			return false;
		}
	}

	return mystack.empty();
}


int main()
{
    return 0;
}

