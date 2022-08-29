#include<iostream>
#include<vector>
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


TreeNode* buildTree(vector<int> preOrder, vector<int> inOrder, int start, int end) {
	int static n = 0;
	if (start > end)
		return NULL;

	TreeNode* root = new TreeNode(preOrder[n]);

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

// class Pair {
// public:
// 	int branch_sum;  //originating from root
// 	int max_Sum;
// 	Pair() {
// 		branch_sum = 0;
// 		max_Sum = 0;
// 	}

// };



//in java no pointer so pass a object of a class Res res and use its data member val to update res
int maxPathSum_helper(TreeNode* root, int &res) {
	// Pair p;
	if (root == NULL) {
		return 0;
	}

	//otherwise 3 cases: 1)max path in lsubtree 2)in rsubtree
	//call recursive to left and right subtree to return there Pair of max paths
	int l = maxPathSum_helper(root->left, res);
	int r = maxPathSum_helper(root->right, res);

	// int op1 = root->data;
	// int op2 = lp.branch_sum + root->data;
	// int op3 = rp.branch_sum + root->data;
	// int op4 = lp.branch_sum + root->data + rp.branch_sum;


	//max path sum for path originating from root
	int curr_ans_root_start = max(max(l, r) + root->data, root->data); //max(op1, max(op2, max(op3, op4)));

	//branch sum fot the current root node
	// p.branch_sum = max(lp.branch_sum, max(rp.branch_sum, 0)) + root->data;
	// p.max_Sum = max(lp.max_Sum, max(rp.max_Sum, curr_ans_trhough_root));

	int max_sum = max(curr_ans_root_start, l + r + root->data);

	res = max(res, max_Sum);

	return curr_ans_root_start;



}


int maxPathSum(TreeNode* root) {
	//otherwise
	Pair ans = maxPathSum_helper(root);
	return max(ans.branch_sum, ans.max_Sum);

}


int main(int argc, char const *argv[])
{
	vector<int> preOrder = { -1}; //{1, 2, 4, 6, 7, 10, 11, 5, 8, 9, 3};
	vector<int> inOrder = { -1}; //{6, 4, 10, 7, 11, 2, 8, 5, 9, 1, 3};
	TreeNode* root = buildTree(preOrder, inOrder, 0, preOrder.size() - 1);

	//bfs(root);

	cout << maxPathSum(root);
	return 0;
}
