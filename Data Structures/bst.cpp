/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

class bst
{
	struct Node
	{
		int num;
		Node *left;
		Node *right;
		Node(int num)
		{
			this->num = num;
			left = NULL;
			right = NULL;
		}
	};

private:
	// Root of BST Tree
	Node *root = NULL;

	// Use this function for easy to understand or non-calling of NULL Node
	/*
	void help_insert(Node *curr,int val)
	{
		// value of element to be inserted < value of curr node
		if (val<curr->num)
		{
			if (curr->left==NULL)
			{
				Node *temp = new Node(val);
				curr->left = temp;
			}
			else
			{
				help_insert(curr->left,val);
			}
		}
		else
		{
			// value of element to be inserted >= value of curr node
			if (curr->right==NULL)
			{
				Node *temp = new Node(val);
				curr->right = temp;
			}
			else
			{
				help_insert(curr->right,val);
			}
		}
	}
	*/

	Node *help_insert(Node *curr, int val)
	{
		if (curr == NULL)
		{
			return new Node(val);
		}

		if (val < curr->num)
		{
			curr->left = help_insert(curr->left, val);
		}
		else
		{
			curr->right = help_insert(curr->right, val);
		}
		return curr;
	}

	bool help_search(Node *curr, int val)
	{
		if (curr == NULL)
		{
			return false;
		}

		if (curr->num == val)
		{
			return true;
		}
		else if (curr->num > val)
		{
			return help_search(curr->left, val);
		}
		else
		{
			return help_search(curr->right, val);
		}
	}

	void help_preOrder(Node *curr)
	{
		if (curr == NULL)
		{
			return;
		}

		cout << curr->num << " ";
		help_preOrder(curr->left);
		help_preOrder(curr->right);
	}

	void help_inOrder(Node *curr)
	{
		if (curr == NULL)
		{
			return;
		}

		help_inOrder(curr->left);
		cout << curr->num << " ";
		help_inOrder(curr->right);
	}

	void help_postOrder(Node *curr)
	{
		if (curr == NULL)
		{
			return;
		}

		help_postOrder(curr->left);
		help_postOrder(curr->right);
		cout << curr->num << " ";
	}

public:
	void insert(int val)
	{
		if (root == NULL)
		{
			root = new Node(val);
			return;
		}
		help_insert(root, val);
	}

	bool search(int val)
	{
		return help_search(root, val);
	}

	void preOrder()
	{
		cout << "Pre-Order Traversal of the Tree: ";
		help_preOrder(root);
		cout << "\n";
	}

	void inOrder()
	{
		cout << "In-Order Traversal of the Tree: ";
		help_inOrder(root);
		cout << "\n";
	}

	void postOrder()
	{
		cout << "Post-Order Traversal of the Tree: ";
		help_postOrder(root);
		cout << "\n";
	}
};

int main()
{
	bst tree;
	tree.insert(25);
	tree.insert(50);
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(12);
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	return 0;
}