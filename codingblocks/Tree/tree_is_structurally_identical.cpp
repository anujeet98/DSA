#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	string s;
	cin >> s;

	if (s == "false")
		return NULL;

	int val;
	if (s == "true") {
		cin >> s;
		val = stoi(s);
	}
	else
		val = stoi(s);

	node* root = new node(val);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void bfs(node* root) {
	if (root == NULL)
		return;
	//otherwise
	queue<node*> Q;

	Q.push(root);
	Q.push(NULL);

	while (!Q.empty()) {
		node* x = Q.front();
		Q.pop();
		if (x != NULL) {
			cout << x->data << " ";
			if (x->left)
				Q.push(x->left);
			if (x->right)
				Q.push(x->right);
		}
		else {
			cout << endl;
			if (!Q.empty())
				Q.push(NULL);
		}
	}
}

bool is_identical(node* root1, node* root2) {
	if (root1 == NULL and root2 == NULL)
		return true;

	if (root1 == NULL)
		return false;
	if (root2 == NULL)
		return false;

	bool l = is_identical(root1->left, root2->left);
	bool r = is_identical(root1->right, root2->right);

	if (l and r)
		return true;
	return false;
}



int main() {
	node* root1 = buildTree();
	node* root2 = buildTree();
	//bfs(root1);
	//bfs(root2);
	//zigzag_print(root);
	if (is_identical(root1, root2))
		cout << "true";
	else
		cout << "false";
	return 0;
}

