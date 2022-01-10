/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

class AVLTree
{
	struct Node
	{
		int data;
		Node *left;
		Node *right;
		int height;
		Node(int data)
		{
			this->data = data;
			this->height = 1;
			this->left = NULL;
			this->right = NULL;
		}
	};

private:
	Node *root = NULL;

	int height(Node *node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return node->height;
	}

	int balanceFactor(Node *n)
	{
		if (n == NULL)
		{
			return 0;
		}
		return height(n->left) - height(n->right);
	}

	Node *leftRotation(Node *x)
	{
		Node *y = x->right;
		Node *t2 = y->left;

		x->right = t2;
		y->left = x;

		x->height = 1 + max(height(x->left), height(x->right));
		y->height = 1 + max(height(y->left), height(y->right));
		return y;
	}

	Node *rightRotation(Node *y)
	{
		Node *x = y->left;
		Node *t2 = x->right;

		y->left = t2;
		x->right = y;

		y->height = 1 + max(height(y->left), height(y->right));
		x->height = 1 + max(height(x->left), height(x->right));
		return x;
	}

	Node *insertRecursive(Node *node, int num)
	{
		if (node == NULL)
		{
			return new Node(num);
		}

		if (node->data < num)
		{
			node->right = insertRecursive(node->right, num);
		}
		else if (node->data > num)
		{
			node->left = insertRecursive(node->left, num);
		}

		// update the height
		node->height = 1 + max(height(node->left), height(node->right));
		int balFactor = balanceFactor(node);
		if (balFactor > 1)
		{
			// right rotation
			if (num < node->left->data)
			{
				return rightRotation(node);
			}
			else
			{
				node->left = leftRotation(node->left);
				return rightRotation(node);
			}
		}
		if (balFactor < -1)
		{
			// left rotation
			if (num > node->right->data)
			{
				return leftRotation(node);
			}
			else
			{
				node->right = rightRotation(node->right);
				return leftRotation(node);
			}
		}
		return node;
	}

	bool help_search(Node *curr, int val)
	{
		if (curr == NULL)
		{
			return false;
		}

		if (curr->data == val)
		{
			return true;
		}
		else if (curr->data > val)
		{
			return help_search(curr->left, val);
		}
		else
		{
			return help_search(curr->right, val);
		}
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	void insert(int num)
	{
		root = insertRecursive(root, num);
	}

	bool search(int val)
	{
		return help_search(root, val);
	}

	void print()
	{
		queue<Node *> q;
		q.push(root);
		while (!q.empty())
		{
			Node *n = q.front();
			q.pop();
			Node *l = n->left;
			Node *r = n->right;
			int lnum = -1;
			int rnum = -1;
			if (l != NULL)
			{
				lnum = l->data;
				q.push(l);
			}
			if (r != NULL)
			{
				rnum = r->data;
				q.push(r);
			}
			cout << "Node " << n->data << " leftChild: " << lnum << "  rightChild: " << rnum << endl;
		}
	}
};

int main()
{
	AVLTree tree;
	tree.insert(10);
	tree.insert(13);
	tree.insert(9);
	tree.insert(8);
	tree.insert(7);
	tree.print();
	return 0;
}