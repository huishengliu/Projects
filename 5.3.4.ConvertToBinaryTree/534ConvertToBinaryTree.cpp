// 534ConvertToBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>

using namespace std;

// Clarification Questions:
// - array can be empty

struct Node 
{
	int value;
	struct Node* left;
	struct Node* right;
};

// [begin, end)
struct Node* ConvertArrayToBinaryTree(vector<int> input, vector<int>::iterator begin, vector<int>::iterator end)
{
	if (input.empty())
		return nullptr;

	vector<int>::iterator mid = begin + (end - begin) / 2;

	struct Node* root = new Node();
	root->value = *mid;
	root->left = ConvertArrayToBinaryTree(input, begin, mid);
	root->right = ConvertArrayToBinaryTree(input, mid + 1, end);

	return root;
}

struct Node* ConvertArrayToBinaryTree(vector<int>::iterator begin, vector<int>::iterator end)
{
	if (begin == end)
		return nullptr;

	vector<int>::iterator mid = begin + (end - begin) / 2;

	struct Node* root = new Node();
	root->value = *mid;
	root->left = ConvertArrayToBinaryTree(begin, mid);
	root->right = ConvertArrayToBinaryTree(mid + 1, end);

	return root;
}


int main()
{
    return 0;
}

