// 521ConstructBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// Clarification Questions:
// - are there duplicates?

struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* ConstructBinaryTree(vector<int> preorder, vector<int> inorder)
{
	if (preorder.size() != inorder.size())
	{
		throw new exception("size not matching");
	}

	if (preorder.empty())
	{
		return nullptr;
	}

	Node* root = new Node();
	root->value = preorder[0];

	auto it = std::find(inorder.begin(), inorder.end(), preorder[0]);
	if (it == inorder.end())
	{
		throw new exception("not found");
	}

	int leftSize = it - inorder.begin();
	int rightSize = inorder.size() - leftSize - 1;

	if (leftSize > 0)
	{
		root->left = ConstructBinaryTree(vector<int>(preorder.begin()+1, preorder.begin()+1+leftSize), vector<int>(inorder.begin(), it));
	}
	if (rightSize > 0)
	{
		root->right = ConstructBinaryTree(vector<int>(preorder.begin()+2+leftSize, preorder.end()), vector<int>(it + 1, inorder.end()));
	}

	return root;
}

int main()
{
	vector<int> a = { 2, 3, 5, 4, 6, 3 };

	cout << a.end() - a.begin() << endl;

    return 0;
}

