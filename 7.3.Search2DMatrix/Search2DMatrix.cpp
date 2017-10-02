// Search2DMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>

using namespace std;

// Clarification Questions:
//
// Observation:
// - essentially binary search on a single dimension array, twister is to find mid point.
// - only the last dimension can be omitted.

bool Search1DArray(int *A, int left, int right, int value);

bool Search2DMatrix(int *A, int m, int n, int value)
{
	return Search1DArray(A, 0, m * n, value);
}

bool Search1DArray(int *A, int left, int right, int value)
{
	int mid = left + (right - left) / 2;
	if (value < A[mid])
	{
		return Search1DArray(A, left, mid, value);
	}
	else if (value > A[mid])
	{
		return Search1DArray(A, mid + 1, right, value);
	}
	else
	{
		return true;
	}
}

int main()
{
    return 0;
}

