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

void Nodes_at_K_level(node* root, int K, vector<int> &ans) {
	if (root == NULL or K < 0)   //if K -ve i.e root is far from target beyond the K distance
		return;

	if (K == 0) {
		ans.push_back(root->data);
		return;
	}

	Nodes_at_K_level(root->left, K - 1, ans);
	Nodes_at_K_level(root->right, K - 1, ans);
}

//returns distance from current node(root) to the target node
int helper_function(node* root, int targetNode, int K, vector<int> &ans) {
	//base case
	if (root == NULL)
		return -1;

	//case when target node reached
	if (root->data == targetNode) {
		Nodes_at_K_level(root, K, ans);
		return 0;   //returns distance from target node to its parent i.e 0
	}

	//case: subtree returns ancestor the distance. ancestor process its adjacent and returns its distance from target back
	//otherwise traverse to target node if target not reached
	int D; //subtree to target dist

	D = helper_function(root -> left, targetNode, K, ans);
	if (D != -1) {  // i.e. target is in left subtree
		if (D + 1 == K)
			ans.push_back(root->data);
		else
			Nodes_at_K_level(root->right, K - D - 2, ans);

		return D + 1;
	}


	// if above is false ONLY THEN BELOW EXECUTES. RETURN PRESENT IN ABOVE
	D = helper_function(root -> right, targetNode, K, ans);
	if (D != -1) { //means target not found in Left subtree. So for subtree to target distance will be the one returned from right subtree
		if (D + 1 == K)
			ans.push_back(root->data);
		else
			Nodes_at_K_level(root->left, K - D - 2, ans);

		return D + 1
	}


	return -1;  //if non of the subtree above contained target node

}

vector<int> printNodesAtK(node * root, int targetNode, int K) {
	vector<int> ans;

	helper_function(root, targetNode, K, ans);
	return ans;

}



int main(int argc, char const * argv[])
{
	int n;
	cin >> n;

	vector<int> preOrder;
	vector<int> inOrder;

	int inp;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		preOrder.push_back(inp);
	}
	for (int i = 0; i < n; i++) {
		cin >> inp;
		inOrder.push_back(inp);
	}

	node* Root = buildTree(preOrder, inOrder, 0, n - 1);
	//cout << "hello";
	//bfs(Root);


	int t;
	cin >> t;
	int targetNode;
	int K;
	while (t--) {
		cin >> targetNode >> K;
		vector<int> ans = printNodesAtK(Root, targetNode, K);
		for (int i : ans)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}
