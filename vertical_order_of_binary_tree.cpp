/* http://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/ */

/* unfinished */

#include <stack>
#include <map>
#include <vector>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
	bool visited;
};

Node* newNode(int data)
{
	Node* newnode = new Node;
	newnode->data = data;
	newnode->left = nullptr;
	newnode->right = nullptr;
	newnode->visited = false;
	return newnode;
}

void PrintVertical(Node* root)
{
	map<int, vector<int>> v_map;
	stack<Node*> node_stack;
	int v_order = 0;
	node_stack.push(root);
	while (!stack.empty())
	{
		Node* cur = stack.top();
		if (cur->left)
		{
			if (!cur->left->visited)
			{
				index--;
				stack.push(cur->left);
				continue;
			}
		}
		if (cur->right)
		{
			index++;
			stack.push(cur->right);
			continue;
		}
		else
		{
			v_map[index].push_back(cur->data);
			cur->visited = true;
		}
	}
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->left->right = newNode(8);
	root->right->right = newNode(7);
	root->right->right->right = newNode(9);
	PrintVertical(root);
}