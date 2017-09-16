// 211RemoveDuplicates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int RemoveDuplicates(int sorted_numbers[], int size)
{
    if (size <= 1) return size;

    int i = 0;
    int j = 1;

    while (j < size)
    {
        while (sorted_numbers[j] == sorted_numbers[i]) ++j;
        if (j<size)
        {
            sorted_numbers[++i] = sorted_numbers[j++];
        }
    }

    return i+1;
}

int main()
{
    return 0;
}

