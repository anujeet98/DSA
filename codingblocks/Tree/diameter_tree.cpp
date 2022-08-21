#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};


//create tree recursively function
Node* BuildTree() {
	int d;
	cin >> d;
	if (d == -1)
		return NULL;
	Node* n = new Node(d);
	n->left = BuildTree();
	n->right = BuildTree();
	return n;
}

int TreeHeight(Node* Root) {
	//base
	if (Root == NULL)
		return 0;

	//rec call h of ls and rs and return max+1;
	int h1 = TreeHeight(Root->left);
	int h2 = TreeHeight(Root->right);
	return max(h1, h2) + 1;
}


//O(n2)
int diameter(Node* Root) {
	if (Root == NULL)
		return 0;

	int case1 = TreeHeight(Root->left) + TreeHeight(Root->right);
	int case2 = diameter(Root->left);
	int case3 = diameter(Root->right);

	return max(max(case1, case2), case3);
}



//better approach
//calculate height and store it while traversing
//no need to calculate height every time

class Pair {
public:
	int height;
	int diameter;
};

Pair diameter_fast(Node* Root) {
	Pair p;
	if (Root == NULL) {
		p.height = p.diameter = 0;
		return p;
	}

	//otherwise compute next height and diameter from values recieved frrom LS and RS
	Pair LS = diameter_fast(Root->left);
	Pair RS = diameter_fast(Root->right);


//COMPUTE pair<H,D> for current node
	p.height = max(LS.height, RS.height) + 1;
	//max of case 1, case 2 case 3
	int case1 = LS.height + RS.height;
	int case2 = LS.diameter;
	int case3 = RS.diameter;
	p.diameter = max(max( case1, case2) , case3);

	return p;

}

int main(int argc, char const *argv[])
{
	Node *Root = BuildTree();
	cout << "Diameter of tree: " << diameter_fast(Root).diameter;

	return 0;
}
