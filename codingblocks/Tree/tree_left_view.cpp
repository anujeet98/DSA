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

//BUILD TREE BFS WISE
Node* buildTree() {
	queue<Node*> Q;
	int d;

	cin >> d;

	Node* n = new Node(d);
	Node* root = n;
	Q.push(n);
	while (!Q.empty()) {
		n = Q.front();
		Q.pop();
		cin >> d;
		if (d == -1)
			n->left = NULL;
		else {
			n->left = new Node(d);
			Q.push(n->left);
		}
		cin >> d;
		if (d == -1)
			n->right = NULL;
		else {
			n->right = new Node(d);
			Q.push(n->right);
		}
	}

	return root;
}

void left_view(Node* Root) {
	if (Root == NULL)
		return;

	//otherwise
	queue<Node*> Q;
	Q.push(Root);
	Q.push(NULL);

	while (!Q.empty()) {
		Node *n = Q.front();
		cout << n->data << endl;
		while (Q.front() != NULL) {
			n = Q.front();
			Q.pop();

			//while poping, push the child nodes
			if (n->left)
				Q.push(n->left);
			if (n->right)
				Q.push(n->right);
		}

		//remove the NULL in Q front
		Q.pop();

		//push the NULL value into Q for row end, only if elements are present in Q
		if (!Q.empty())
			Q.push(NULL);
	}

}

int main(int argc, char const *argv[])
{
	Node* Root = buildTree();
	//bfs(Root);
	//cout << endl << "Right view :" << endl;
	left_view(Root);
	return 0;
}
