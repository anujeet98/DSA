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

void bfs(Node* root) {
	queue<Node*> Q;
	if (root == NULL)
		return;

	//otherwise push that root into queue
	Q.push(root);
	Q.push(NULL);
	while (!Q.empty()) {
		Node* x = Q.front();
		Q.pop();

		if (x == NULL) {
			cout << endl;
			if (!Q.empty()) {
				Q.push(NULL);
			}
		}

		else {
			//if not null push its childs to Q and print its data
			if (x->left != NULL)
				Q.push(x->left);
			if (x->right != NULL)
				Q.push(x->right);

			cout << x->data << " ";
		}

	}
}
//(int *PreOrder, int *InOrder, int i, int start, int end)
Node* build_Tree_from_Inorder_preorder(int *PreOrder, int *InOrder, int start, int end) {
	static int i = 0;  //initialized once; or else use by passing i as paramrter example comented
	if (start > end) {
		return NULL;
	}

	//iteratively search index of root(ith element in preorder) from Inorder
	//make ith node as root
	Node* root = new Node(PreOrder[i]);

	int index = -1; // to find indext of current root in inorder array
	for (int j = start; j <= end; j++) {
		if (InOrder[j] == PreOrder[i]) {
			index = j;
			break;
		}
	}
	//elements from start to index-1 is LS of root
	//elements from index+1 to end is RS of root
	//call rec to build it
	i++; //increment i for LS
	root->left = build_Tree_from_Inorder_preorder(PreOrder, InOrder, start, index - 1);
	// i++;//increment i for RS  DO NOT INCREMENT THIS. IT WILL MOVE NEXT NODE IN PRE ORDER FUTHER AHEAD. JUST NEED TO MOVE ONLY ONE NODE
	root->right = build_Tree_from_Inorder_preorder(PreOrder, InOrder, index + 1, end);
	//cout << "h" << endl;

	return root;


}




int main(int argc, char const *argv[])
{
	//Node* Root = buildTree();
	// int *PreOrder;
	// int *InOrder;
	int n;
	// cin >> n;

	// //read preorder array
	// for (int i = 0; i < n; i++) {
	// 	cin >> PreOrder[i];
	// }
	// //read Inorder array
	// for (int i = 0; i < n; i++) {
	// 	cin >> InOrder[i];
	// }

	// cout << "i";

	n = 8;
	int PreOrder[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int InOrder[] = {3, 2, 8, 4, 1, 6, 7, 5};

	Node* Root = build_Tree_from_Inorder_preorder(PreOrder, InOrder, 0, n - 1);

	cout << "built tree :" << endl;
	bfs(Root);

	return 0;
}
