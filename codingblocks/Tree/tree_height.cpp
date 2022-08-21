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

int TreeHeight(Node* Root) {
	//base
	if (Root == NULL)
		return 0;

	//rec call h of ls and rs and return max+1;
	int h1 = TreeHeight(Root->left);
	int h2 = TreeHeight(Root->right);
	return max(h1, h2) + 1;
}




int main(int argc, char const *argv[])
{
	Node *Root = BuildTree();
	cout << "Height of tree: " << TreeHeight(Root) << endl;
	return 0;
}
