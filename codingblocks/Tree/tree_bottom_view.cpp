#include<iostream>
#include<queue>
#include<vector>
#include<map>

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



//BOTTOM VIEW USING MAP DFS RECURSIVE APPROACH
void bottom_view_DFS_helper(TreeNode* root, int height, int hd, map<int , pair<int, int> > &m) { //m stores node and hd
	if (root == NULL)
		return;

	if (m.find(hd) == m.end()) { //node at this hd doesn't exist do add it into map
		m[hd] = make_pair(root->data, height);
	}
	else {
		//compare height, if curr node has greater height then update is
		pair<int, int> p;
		if (m[hd].second <= height) {
			p.first = root->data;
			p.second = height;
			m[hd] = p;
		}
	}

	bottom_view_DFS_helper(root->left, height + 1, hd - 1, m);
	bottom_view_DFS_helper(root->right, height + 1, hd + 1, m);

}


vector<int> bottom_view_DFS(TreeNode*  root) {
	vector<int> ans;
	map < int, pair<int, int>> m;
	bottom_view_DFS_helper(root, 0, 0, m);
	map < int, pair < int, int > > ::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		pair < int, int > p = it -> second;
		ans.push_back(p.first);
	}

	return ans;
}



//BOTTOM VIEW USING QUEUE AND MAP BFS APPROACH
vector<int> bottom_view(TreeNode* root) {
	vector<int> ans;  //to store ans bootom view
	queue<pair<TreeNode*, int>> Q; //for BFS also store hd (horizontal distance from center)
	map<int, int> x; //to store updated val for each horizontal length

	if (root == NULL)
		return ans;

	Q.push(make_pair(root, 0));

	while (!Q.empty()) {
		TreeNode* n = Q.front().first;
		int hd = Q.front().second;
		Q.pop();

		x[hd] = n->data;  //update the map for respective hd position

		if (n->left)
			Q.push(make_pair(n->left, hd - 1));

		if (n->right)
			Q.push(make_pair(n->right, hd + 1));

	}

	//fill the ans vector using the map values
	for (auto i : x) {
		ans.push_back(i.second);
	}

	return ans;


}


int main(int argc, char const *argv[])
{
	TreeNode* root = buildTree();
	bfs(root);

	vector<int> ans;
	//BFS APPROACH USING Q AND MAP
	//ans = bottom_view(root);

	//DFS RECURSIVE APPROACH
	ans = bottom_view_DFS(root);
	for (int i : ans)
		cout << i << " ";
	return 0;
}
