#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

//create tree recursively function
Node* BuildTree() {
	int d;
	cin >> d;
	if (d == -1)
		return NULL;
	Node* n = new Node(d);
	n->left = BuildTree();
	n->right = BuildTree();
	return n;
}

//COUNT NODES
int CountNodes(Node *Root) {
	if (Root == NULL)
		return 0;

	int c1 = CountNodes(Root->left);
	int c2 = CountNodes(Root->right);
	return 1 + c1 + c2;
}

//SUM NODES
int SumNodes(Node *Root) {
	if (Root == NULL)
		return 0;

	int s1 = SumNodes(Root->left);
	int s2 = SumNodes(Root->right);
	return Root->data + s1 + s2;
}

int main(int argc, char const *argv[])
{
	Node *Root = BuildTree();

	cout << "Count nodes: " << CountNodes(Root) << endl;
	cout << "Sum of nodes: " << SumNodes(Root) << endl;
	return 0;
}
