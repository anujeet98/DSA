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

int TreeHeight(Node* Root) {
	//base
	if (Root == NULL)
		return 0;

	//rec call h of ls and rs and return max+1;
	int h1 = TreeHeight(Root->left);
	int h2 = TreeHeight(Root->right);
	return max(h1, h2) + 1;
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

int sum_Replacement(Node* Root) {
	if (Root == NULL)
		return 0;

	//if leaf node no need to update its value
	//return value is data in it
	if (Root->left == NULL and Root->right == NULL)
		return Root->data;

	//otherwise
	//1st store data;
	int d = Root->data;
	//get LS sumReplacement and RS sumreplacement
	int leftSum = sum_Replacement(Root->left);
	int rightSum = sum_Replacement(Root->right);

	//now update curr node with sum replacement value
	Root->data = leftSum + rightSum;

	//return updated value + old value
	return Root->data + d;
}


int main(int argc, char const *argv[])
{
	Node *Root = BuildTree();

	cout << "bfs before" << endl;
	LevelOrder_BFS(Root);
	cout << endl;

	sum_Replacement(Root);

	cout << "After replacement" << endl;
	LevelOrder_BFS(Root);

	return 0;
}
