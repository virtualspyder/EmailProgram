// Binary Search Tree algorithm
// The structure is a binary search tree
#include "subscriber.h"

extern string stringLower(string s);

class BinarySearchTree
{
	map<string, Subscriber> tree;
	public : 
	typedef map<string, Subscriber>::iterator iterator;

	bool add(Subscriber &sub)
	{
		string s = stringLower(sub.name);
		if(tree.find(s) == tree.end()) {
			tree[s] = sub;
			return true;			
		}
		return false;
	}

	bool find(string name, Subscriber *&result)
	{
		string s = stringLower(name);
		if(tree.find(s) == tree.end()) {
			result = NULL;
			return false;
		}

		result = &tree[s];
		return true;
	}

	bool remove(string name)
	{
		string s = stringLower(name);
		iterator it = tree.find(s);
		if(it == tree.end()) {
			return false;
		}

		tree.erase(it);
		return true;
	}

	bool empty()
	{
		return tree.empty();
	}

	size_t size()
	{
		return tree.size();
	}

	void clear()
	{
		tree.clear();
	}

	iterator begin()
	{
		return tree.begin();
	}

	iterator end()
	{
		return tree.end();
	}
};