// 514LevelOrderTraversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int value;
	struct node* left;
	struct node* right;
};

// Output all node as one sequence
// Space complexity: O(n)
vector<int> BinaryTreeLevelTraversal(struct node *root)
{
	queue<struct node *> q;
	vector<int> result;

	if (root == nullptr)
	{
		return result;
	}

	q.push(root);
	while (!q.empty())
	{
		struct node* p = q.front();
		q.pop();

		result.push_back(p->value);

		if (p->left) q.push(p->left);
		if (p->right) q.push(p->right);
	}

	return result;
}

// Output each level as one sequence
vector<vector<int>> BinaryTreeLevelTraversal2(struct node *)
{

}

int main()
{
    return 0;
}

