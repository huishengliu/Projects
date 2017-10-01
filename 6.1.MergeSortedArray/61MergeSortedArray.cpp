// 61MergeSortedArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <assert.h>

using namespace std;

// Clarification Questions:
// - A has enough space for B as well

// Observation
// - merge backwards

void MergeSortedArray(vector<int>& A, const vector<int>& B)
{
	assert(A.capacity() >= A.size() + B.size());

	size_t total = A.size() + B.size();

	size_t lastAB = total - 1;
	size_t lastA = A.size() - 1;
	size_t lastB = B.size() - 1;

	do
	{
		if (lastA == 0 && lastB == 0)
		{
			break;
		}

		if (lastB == 0)
		{
			A[lastAB--] = A[lastA--];
		}
		else if (lastA == 0)
		{
			A[lastAB--] = A[lastB--];
		}
		else if (A[lastA] > B[lastB])
		{
			A[lastAB--] = A[lastA--];
		}
		else
		{
			A[lastAB--] = B[lastB--];
		}
	} while (lastAB >= 0);
}

void MergeSortedArray2(vector<int>& A, const vector<int>& B)
{
	size_t lastAB = A.size() + B.size() - 1;
	size_t lastA = A.size() - 1;
	size_t lastB = B.size() - 1;

	while (lastA >= 0 && lastB >= 0)
	{
		A[lastAB--] = A[lastA] > B[lastB] ? A[lastA--] : B[lastB--];
	}

	while (lastB >= 0)
	{
		A[lastAB--] = B[lastB--];
	}
}

int main()
{
    return 0;
}

