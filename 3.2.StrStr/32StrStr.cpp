// 32StrStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const char *StrStr(const char *text, const char *str)
{
	const char *p = text;
	const char *q = str;

	if (text == nullptr || str == nullptr || *text == '\0' || *str == '\0')
	{
		return nullptr;
	}

	while (*p)
	{
		while (*p != *q && *p)
		{
			p++;
		}

		const char *start = p;
		while (*p == *q && *p && *q)
		{
			++p; ++q;
		}

		if (*q == '\0')
		{
			return p;
		}

		p = start + 1;
	}

	return nullptr;
}

const char *StrStr2(const char *text, const char *str)
{
	if (text == nullptr || str == nullptr || *text == '\0' || *str == '\0')
	{
		return nullptr;
	}

	const char *p = text;
	while (*p)
	{
		const char *start = p;
		const char *q = str;

		while (*p == *q && *p && *q)
		{
			p++;
			q++;
		}

		if (*q == '\0')
		{
			return start;
		}

		p = start + 1;
	}
}

const char *StrStr3(const char *text, const char *str)
{
	if (text == nullptr || str == nullptr || *text == '\0' || *str == '\0')
	{
		return nullptr;
	}

	const char *p = text;
	const char *start = p;
	const char *q = str;
	while (*p)
	{
		if (*p == *q)
		{
			p++; q++;
		}
		else
		{
			p = start + 1;
			q = str;
		}
	}
}

int main()
{
    return 0;
}

