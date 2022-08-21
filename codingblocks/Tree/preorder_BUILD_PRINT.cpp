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

/*
//BFS TREE BUILD
Node* buildTree() {
	queue<Node*> Q;
	int d;

	cin >> d;

	Node* n=new Node(d);
	Node* root=n;
	Q.push(n);
	while(!Q.empty()){
		n=Q.front();
		Q.pop();
		cin>>d;
		if(d==-1)
			n->left=NULL;
		else{
			n->left=new Node(d);
			Q.push(n->left);
		}
		cin>>d;
		if(d==-1)
			n->right=NULL;
		else{
			n->right=new Node(d);
			Q.push(n->right);
		}
	}

	return root;
}
*/

//preorder print
void PreOrder(Node *Root) {
	if (Root == NULL)
		return;

	cout << Root->data << " ";
	PreOrder(Root->left);
	PreOrder(Root->right);
}

int main(int argc, char const *argv[])
{
	Node *Root = BuildTree();

	cout << "PreOrder: "; PreOrder(Root); cout << endl;
	return 0;
}
