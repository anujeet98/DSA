#include<iostream>
#include<queue>

using namespace std;


class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

TreeNode* buildTree() {
	queue<TreeNode*> Q;
	int d;
	cin >> d;
	TreeNode* root = new TreeNode(d);
	//TreeNode* root = n;

	Q.push(root);

	while (!Q.empty()) {
		TreeNode* n = Q.front();
		Q.pop();
		//cout << Q.empty() << endl;
		cin >> d;
		if (d == -1) {
			n->left = NULL;
		}
		else {
			n->left = new TreeNode(d);
			Q.push(n->left);
		}
		cin >> d;
		if (d == -1)
			n->right = NULL;
		else {
			n->right = new TreeNode(d);
			Q.push(n->right);
		}
	}

	return root;
}

void bfs(TreeNode* root) {
	if (root == NULL)
		return;
	//otherwise
	queue<TreeNode*> Q;

	Q.push(root);
	Q.push(NULL);

	while (!Q.empty()) {
		TreeNode* x = Q.front();
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

int findPathLength(TreeNode* root, int a, int length) {
	if (root == NULL)
		return -1;

	if (root->data == a)
		return length;

	int len = findPathLength(root->left, a, length + 1);
	if (len != -1)
		return len;
	return findPathLength(root->right, a, length + 1);
}

TreeNode* LCA(TreeNode* root, int a, int b) {
	if (root == NULL)
		return root;
	//cout << root->data;

	//otherwise
	if (root->data == a or root->data == b)
		return root;

	TreeNode* l = LCA(root->left, a, b);
	TreeNode* r = LCA(root->right, a, b);

	if (l != NULL and r != NULL)
		return root;
	// if (l == NULL and r == NULL)  //if both null last condn returns null right condn
	// 	return NULL;
	if (l != NULL)
		return l;
	return r;
}

int shortestPath_length(TreeNode* root, int a, int b) {
	if (root == NULL)
		return 0;

	//otherwise find LCA first
	TreeNode* lca = LCA(root, a, b);
	int p1 = findPathLength(lca, a , 0);
	int p2 = findPathLength(lca, b, 0);

	return p1 + p2;

}

int main(int argc, char const *argv[])
{
	TreeNode* root = buildTree();
	//bfs(root);

	int a, b;
	cin >> a >> b;
	cout << shortestPath_length(root, a, b);
	return 0;
}
