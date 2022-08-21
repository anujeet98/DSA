//print all levels. call print kth level for all height levels. worst case O(n2) in skewed tree
//better approach BFS. level order traversal using Queue. O(n)

#include<iostream>
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

void print_Kth_level(Node* Root, int K) {
	if (Root == NULL)
		return;

	if (K == 1) {
		cout << Root->data << " ";
		return;
	}

	print_Kth_level(Root->left, K - 1);
	print_Kth_level(Root->right, K - 1);

}

void printAllLevels_LevelOrder(Node* Root) {
	//compute height first
	int h = TreeHeight(Root);

	//print for all height
	for (int i = 1; i <= h; ++i)
	{
		print_Kth_level(Root, i);
		cout << endl;
	}
}


int main(int argc, char const *argv[])
{
	Node *Root = BuildTree();
	printAllLevels_LevelOrder(Root);
	return 0;
}
