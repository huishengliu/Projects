// 211RemoveDuplicates.cpp : Defines the entry point for the console application.
// Solution 3*: no nested loop, clean code.
//

#include "stdafx.h"

int RemoveDuplicates(int sorted_numbers[], int size)
{
    if (size <= 1) return size;

    int i = 0;
    int j = 1;

    while (j < size)
    {
        while (sorted_numbers[j] == sorted_numbers[i] && j < size) ++j;
        if (j<size)
        {
            sorted_numbers[++i] = sorted_numbers[j++];
        }
    }

    return i+1;
}

int RemoveDuplicates2(int sorted_numbers[], int size)
{
    int i = 0;
    int j = 0;

	if (size == 0) return 0;

    while (j < size)
    {
        sorted_numbers[i++] = sorted_numbers[j++];
        while (sorted_numbers[j] == sorted_numbers[i-1] && j < size) ++j;
    }

	return i;
}

int RemoveDuplicates3(int sorted_numbers[], int size)
{
    int i = 0;
    int j = 0;

	if (size == 0) return 0;

    while (j < size)
    {
        if (i == j || sorted_numbers[i] == sorted_numbers[j])
        {
            j++;
            continue;
        }
        sorted_numbers[++i] = sorted_numbers[j++];
    }

	return i + 1;
}

int RemoveDuplicates3_1(int sorted_numbers[], int size)
{
	int i = 0;
	int j = 0;

	if (size == 0) return 0;

	while (j < size)
	{
		if (i != j && sorted_numbers[i] != sorted_numbers[j])
		{
			sorted_numbers[++i] = sorted_numbers[j];
		}
		j++;
	}

	return i + 1;
}

int RemoveDuplicates3_2(int sorted_numbers[], int size)
{
	int i = 0;

	if (size == 0) return 0;

	for (int j = 0; j < size; j++)
	{
		if (i != j && sorted_numbers[i] != sorted_numbers[j])
		{
			sorted_numbers[++i] = sorted_numbers[j];
		}
	}

	return i + 1;
}

int RemoveDuplicates3_3(int sorted_numbers[], int size)
{
	int i = 0;

	if (size == 0) return 0;

	for (int j = 1; j < size; j++)
	{
		if (sorted_numbers[i] != sorted_numbers[j])
		{
			sorted_numbers[++i] = sorted_numbers[j];
		}
	}

	return i + 1;
}

void print(int sorted_numbers[], int size)
{
    printf("size: %d\n", size);
    for (int i=0; i<size; ++i)
    {
        printf("%d ", sorted_numbers[i]);
    }
    printf("\n");
}

int main()
{
	int sn[] = { 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 5, 5 };
    int s1 = RemoveDuplicates(sn, sizeof(sn)/sizeof(int));
    print(sn, s1);

	int sn2[] = { 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 5, 5 };
    int s2 = RemoveDuplicates2(sn2, sizeof(sn2)/sizeof(int));
    print(sn2, s2);

	int sn3[] = { 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 5, 5 };
    int s3 = RemoveDuplicates3(sn3, sizeof(sn3)/sizeof(int));
    print(sn3, s3);

	int sn3_1[] = { 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 5, 5 };
	int s3_1 = RemoveDuplicates3_1(sn3_1, sizeof(sn3_1) / sizeof(int));
	print(sn3_1, s3_1);

	int sn3_2[] = { 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 5, 5 };
	int s3_2 = RemoveDuplicates3_2(sn3_2, sizeof(sn3_2) / sizeof(int));
	print(sn3_2, s3_2);

	return 0;
}

