// Trie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>

using namespace std;

class TrieNode
{
public:
	TrieNode(char arg)
	{
		c = arg;
		for (int i = 0; i < 26; ++i) children[i] = nullptr;
	}

	TrieNode* children[26];
	char c;
	bool isWord;
};

class Trie
{
public:
	Trie() : root(' ')
	{
	}

	void AddWord(const string& word)
	{
		TrieNode* current = &root;
		for (auto it = word.begin(); it < word.end(); ++it)
		{
			if (current->children[*it - 'a'] == nullptr)
			{
				current->children[*it - 'a'] = new TrieNode(*it);
			}
			current = current->children[*it - 'a'];
		}
		current->isWord = true;
	}

	bool Search(const string& word)
	{
		TrieNode* current = &root;
		for (auto it = word.begin(); it < word.end(); ++it)
		{
			if (current->children[*it - 'a'] == nullptr)
				return false;
			current = current->children[*it - 'a'];
		}

		return current->isWord;
	}

	bool StartWith(const string& word)
	{
		TrieNode* current = &root;
		for (auto it = word.begin(); it < word.end(); ++it)
		{
			if (current->children[*it - 'a'] == nullptr)
				return false;
			current = current->children[*it - 'a'];
		}

		return false;
	}

private:
	TrieNode root;
};

int main()
{
    return 0;
}

