//find LCA (lowest common ancestor) for two given nodes


#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node {
public:
	int data;
	node* left;
	node*right;

	node (int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(vector<int> preOrder, vector<int> inOrder, int start, int end) {
	int static n = 0;
	if (start > end)
		return NULL;

	node* root = new node(preOrder[n]);

	int root_index = -1;
	for (int i = start; i <= end; i++) {
		if (inOrder[i] == root->data) {
			root_index = i;
			break;
		}
	}

	n++;
	root->left = buildTree(preOrder, inOrder, start, root_index - 1);
	root->right = buildTree(preOrder, inOrder, root_index + 1, end);

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

node* lowestCommonAncestor(node* root, node* p, node* q) {
	//if root null return as nothing found
	if (root == NULL)
		return root;

	//if root is any of the p or q then it might be lca (as other node might be below it) so return it. lca might change while travesing back if we get other node is some other branch
	if (root->data == p->data or root->data == q->data)
		return root;

	//rec search for lca in subtrees
	node* leftans = lowestCommonAncestor(root->left, p, q);
	node* rightans = lowestCommonAncestor(root->right, p, q);


	//if both subtree return addr then p and q are branched from here. so this is LCA return it
	if (leftans != NULL and rightans != NULL)
		return root;

	//otherwise if one subtree return addr, other will be null. in this case that might be LCA so return it
	if (leftans != NULL)
		return leftans;

	//otherwise it is opposite that is right has targets and left is null
	return rightans;
}


node* getP_Q_addr(node* root, int x) {
	if (root == NULL)
		return root;

	if (root->data == x)
		return root;

	node* l = getP_Q_addr(root->left, x);
	if (l != NULL)
		return l;
	return getP_Q_addr(root->right, x);
}


int main(int argc, char const * argv[])
{
	vector<int> preOrder = {1, 2, 4, 6, 7, 10, 11, 5, 8, 9, 3};
	vector<int> inOrder = {6, 4, 10, 7, 11, 2, 8, 5, 9, 1, 3};
	node* root = buildTree(preOrder, inOrder, 0, preOrder.size() - 1);

	//bfs(root);

	int p, q;
	cin >> p >> q;
	node* P = getP_Q_addr(root, p);
	node* Q = getP_Q_addr(root, q);
	//cout << P << " " << Q << endl;
	node* lca = lowestCommonAncestor(root, P, Q);
	cout << "LCA: " << lca->data;
	return 0;
}
