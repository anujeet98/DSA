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

Node* buildTree() {
	int d;
	Node* n = NULL;
	cin >> d;
	if (d == -1) {
		return NULL;
	}
	else {
		n = new Node(d);
		n->left = buildTree();
		n->right = buildTree();
	}
	return n;
}

void right_view_dfs(Node* Root, int &max_visited_level, int curr_level) {
	if (Root == NULL)
		return;

	//otherwise

	//dfs traverse but right-node-left pattern
	if (curr_level > max_visited_level) { //max_visited_level as curr and print node since it is first element from right in this level
		cout << Root->data << endl;
		max_visited_level = curr_level;
	}
	//else ignore that node as level is already visited

	//now traveser recursively further in the above mentioned pattern
	right_view_dfs(Root->right, max_visited_level, curr_level + 1);
	right_view_dfs(Root->left, max_visited_level, curr_level + 1);

}

void bfs(Node* Root) {
	if (Root == NULL)
		return;

	//otherwise
	queue<Node*> Q;
	Q.push(Root);
	Q.push(NULL);

	while (!Q.empty()) {
		Node* n = Q.front();
		Q.pop();
		if (n != NULL) {
			cout << n->data << " ";
			if (n->left)
				Q.push(n->left);
			if (n->right)
				Q.push(n->right);
		}
		else { //n==NULL
			cout << endl;
			if (!Q.empty()) {
				Q.push(NULL);
			}
		}

	}
}

int main(int argc, char const *argv[])
{
	Node* Root = buildTree();
	bfs(Root);
	cout << endl << "Right view :" << endl;
	int max_visited_level = -1;
	int curr_level = 0;
	right_view_dfs(Root, max_visited_level, curr_level);
	return 0;
}
