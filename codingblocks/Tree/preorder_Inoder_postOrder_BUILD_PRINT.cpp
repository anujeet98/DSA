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

//preorder print
void PreOrder(Node *Root) {
	if (Root == NULL)
		return;

	cout << Root->data << " ";
	PreOrder(Root->left);
	PreOrder(Root->right);
}
//postorder print
void PostOrder(Node *Root) {
	if (Root == NULL)
		return;

	PostOrder(Root->left);
	PostOrder(Root->right);
	cout << Root->data << " ";
}
//InOrder print
void InOrder(Node *Root) {
	if (Root == NULL)
		return;

	InOrder(Root->left);
	cout << Root->data << " ";
	InOrder(Root->right);
}

int main(int argc, char const *argv[])
{
	Node *Root = BuildTree();

	cout << "PreOrder: "; PreOrder(Root); cout << endl;
	cout << "InOrder: "; InOrder(Root); cout << endl;
	cout << "PostOrder: "; PostOrder(Root); cout << endl;
	return 0;
}
