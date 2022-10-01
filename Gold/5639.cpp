#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

Node* insert(Node* node, int data)
{
	if (node == NULL)
	{
		node = new Node();
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);

	return node;
}

void trav(Node* node)
{
	if (node == NULL)
		return;

	if(node->left != NULL)
		trav(node->left);
	if(node->right != NULL)
		trav(node->right);
	cout << node->data << '\n';
}

int main()
{
	fastio;
	Node* root = NULL;
	int x;
	while (cin >> x)
	{
		if (x == EOF) break;

		root = insert(root, x);
	}

	trav(root);
}