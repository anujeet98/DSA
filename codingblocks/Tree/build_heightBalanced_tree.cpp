#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node*right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void bfs(Node* root) {
	queue<Node*> Q;
	if (root == NULL)
		return;

	//otherwise push that root into queue
	Q.push(root);
	Q.push(NULL);
	while (!Q.empty()) {
		Node* x = Q.front();
		Q.pop();

		if (x == NULL) {
			cout << endl;
			if (!Q.empty()) {
				Q.push(NULL);
			}
		}

		else {
			//if not null push its childs to Q and print its data
			if (x->left != NULL)
				Q.push(x->left);
			if (x->right != NULL)
				Q.push(x->right);

			cout << x->data << " ";
		}

	}
}

Node* build_heightBalanced_Tree(int *arr, int start, int end) {
	//base case
	if (start > end) {
		return NULL;
	}

	//otherwise create node as mid value and rec call to build LS and RS
	int mid = (start + end) / 2;
	Node* root = new Node(arr[mid]);
	root->left = build_heightBalanced_Tree(arr, start, mid - 1);
	root->right = build_heightBalanced_Tree(arr, mid + 1, end);

	return root;

}




int main(int argc, char const *argv[])
{
	//Node* Root = buildTree();
	int *arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Node* Root = build_heightBalanced_Tree(arr, 0, n - 1);

	cout << "balanced tree from array :" << endl;
	bfs(Root);

	return 0;
}
