#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

void insertAtEnd(Node*&Head, int data) {
	Node*n = new Node(data);
	if (Head == NULL) {
		Head = n;
		return;
	}
	Node*Curr = Head;
	while (Curr->next != NULL) {
		Curr = Curr->next;
	}
	Curr->next = n;
}

bool isPalin_LL(Node*Head) {
	Node*curr = Head;
	string num = "";
	while (curr != NULL) {
		num += '0' + curr->data;
		curr = curr->next;
	}
	string rev = num;
	reverse(num.begin(), num.end());
	if (num == rev)
		return true;
	return false;
}

int main() {
	int N;
	cin >> N;
	int node_val;
	Node*Head = NULL;

	while (N--) {
		cin >> node_val;
		insertAtEnd(Head, node_val);
	}
	if (!isPalin_LL(Head))
		cout << "false";
	else
		cout << "true";

	return 0;

}