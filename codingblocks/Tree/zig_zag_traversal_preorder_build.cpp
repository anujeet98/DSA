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

void zigzag_print(node* root) {
	if (root == NULL)
		return;
	queue<node*>Q;
	Q.push(root);
	Q.push(NULL);
	int level = 0;

	while (!Q.empty()) {
		node* n = Q.front();
		vector<int> vec;
		while (!Q.empty() and n != NULL) {
			if (level % 2 == 1)
				vec.push_back(n->data);
			else
				cout << n->data << " ";

			if (n->left)
				Q.push(n->left);
			if (n->right)
				Q.push(n->right);

			Q.pop();
			n = Q.front();

		}
		if (level % 2 == 1)
		{
			for (int i = vec.size() - 1; i >= 0; i--)
				cout << vec[i] << " ";
		}
		if (n == NULL) {
			Q.pop();
			level++;
		}
		if (!Q.empty())
			Q.push(NULL);
	}
}


int main() {
	node* root = buildTree();
	//bfs(root);
	zigzag_print(root);
	return 0;
}



//LEETCODE SUBMISSION BELOW
/*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode*>Q;
        Q.push(root);
        Q.push(NULL);
        int level = 0;

        while (!Q.empty()) {
            TreeNode* n = Q.front();
            vector<int> vec;
            while (!Q.empty() and n != NULL) {
                vec.push_back(n->val);

                if (n->left)
                    Q.push(n->left);
                if (n->right)
                    Q.push(n->right);

                Q.pop();
                n = Q.front();

            }
            if (level % 2 == 1)
                reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            if (n == NULL) {
                Q.pop();
                level++;
            }
            if (!Q.empty())
                Q.push(NULL);
        }
        return ans;
    }

    */