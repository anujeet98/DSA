#include<iostream>
#include<queue>
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

void LevelOrder_BFS(Node* Root) {
	queue<Node*> Q;

	if (Root != NULL)
		Q.push(Root);

	//for fomatting
	Q.push(NULL);

	while (!Q.empty()) {
		Node* x = Q.front();
		Q.pop();

		//for formatting
		if (x == NULL) {
			cout << endl;

			//since null that means we have pushed all elements of this node. So push NULL; if Q not empty that is not last level
			if (!Q.empty())
				Q.push(NULL);
		}

		else {
			if (x->left != NULL)
				Q.push(x->left);
			if (x->right != NULL)
				Q.push(x->right);

			cout << x->data << " ";
		}

	}
}

int main(int argc, char const *argv[])
{
	Node *Root = BuildTree();
	LevelOrder_BFS(Root);

	return 0;
}
