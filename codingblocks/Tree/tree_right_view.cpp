#include<iostream>
#include<queue>
using namespace std;


class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree() {
	int d;
	Node* n = NULL;
	cin >> d;
	if (d == -1) {
		return NULL;
	}
	else {
		n = new Node(d);
		n->left = buildTree();
		n->right = buildTree();
	}
	return n;
}

void right_view(Node* Root) {
	if (Root == NULL)
		return;

	//otherwise
	queue<Node*> Q;
	Q.push(Root);
	Q.push(NULL);

	while (!Q.empty()) {
		Node *n = NULL;
		while (Q.front() != NULL) {
			n = Q.front();
			Q.pop();

			//while poping, push the child nodes
			if (n->left)
				Q.push(n->left);
			if (n->right)
				Q.push(n->right);
		}
		//n contains rightmost element
		cout << n->data << endl;

		//remove the NULL in Q front
		Q.pop();

		//push the NULL value into Q for row end, only if elements are present in Q
		if (!Q.empty())
			Q.push(NULL);
	}

}

void bfs(Node* Root) {
	if (Root == NULL)
		return;

	//otherwise
	queue<Node*> Q;
	Q.push(Root);
	Q.push(NULL);

	while (!Q.empty()) {
		Node* n = Q.front();
		Q.pop();
		if (n != NULL) {
			cout << n->data << " ";
			if (n->left)
				Q.push(n->left);
			if (n->right)
				Q.push(n->right);
		}
		else { //n==NULL
			cout << endl;
			if (!Q.empty()) {
				Q.push(NULL);
			}
		}

	}
}

int main(int argc, char const *argv[])
{
	Node* Root = buildTree();
	bfs(Root);
	cout << endl << "Right view :" << endl;
	right_view(Root);
	return 0;
}
