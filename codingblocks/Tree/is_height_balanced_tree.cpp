#include<iostream>

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

Node* buildTree() {
	int d;
	cin >> d;

	if (d == -1) {
		return NULL;
	}

	//otherwise
	Node* root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}


class HBPair {
public:
	int height;
	bool balance;
};

HBPair isHeightBalanced(Node* Root) {
	HBPair p;
	if (Root == NULL) {
		//height is 0 and balance is true if root null
		p.height = 0;
		p.balance = true;
		return p;
	}

	//otherwise to return HBPair from computing is values returned from child
	HBPair left = isHeightBalanced(Root->left);
	HBPair right = isHeightBalanced(Root->right);

	//curr height is below formula from its child's height
	p.height = max(left.height, right.height) + 1;
	//is current balcned by knowing its child returned pair values
	if (abs(left.height - right.height) <= 1 && left.balance && right.balance) {
		p.balance = true;
	}
	else
		p.balance = false;

	return p;
}



int main(int argc, char const *argv[])
{
	Node* Root = buildTree();
	if (isHeightBalanced(Root).balance) {
		cout << "Yes height balanced" << endl;
	}
	else
		cout << "Not height balanced" << endl;
	return 0;
}
