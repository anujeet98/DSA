#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class TreeNode {
public:
	int data;
	vector<TreeNode *> children;
};


void display(TreeNode *root) {
	//base
	if (root == NULL)
		return;

	string str = root->data + " -> ";

	for (TreeNode *child : root->children) {
		str += child->data + ", ";
	}
	str += ".";

	cout << str << endl;

	for (TreeNode *child : root->children) {
		display(child);
	}

}

int main() {

	vector <int> arr{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
	stack<TreeNode *>stk;
	TreeNode *Root;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == -1) { // if -1, all children of node on top of stack is travesed. So we can remove it now
			stk.pop();
		}
		else {    //else if element appears, check top of the stack node. add this curr node as child of top node and push this node to stack
			TreeNode *n;
			n->data = arr[i];
			if (stk.empty()) {    //stack is empty i.e this curr node is ROOT
				Root = n;
			}
			else {         //else add as child node of node on top
				stk.top()->children.push_back(n);
			}

			//push newly created node on to the stack;
			stk.push(n);
		}

	}

	//cout << "h";
	display(Root);
	return 0;
}
