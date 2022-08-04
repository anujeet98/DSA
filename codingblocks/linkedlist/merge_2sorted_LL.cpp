#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtTail(Node*&Head, int d) {
	if (Head == NULL) {
		Head = new Node(d);
		return;
	}

	Node*curr = Head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = new Node(d);
	return;
}

Node* take_input() {
	int d;
	cin >> d;

	Node*Head = NULL;
	while (d != -1) {
		insertAtTail(Head, d);
		cin >> d;
	}
	return Head;
}

void print(Node*Head) {
	Node*curr = Head;
	while (curr != NULL) {
		cout << curr->data << "->";
		curr = curr->next;
	}
	cout << endl;
}

ostream& operator<<(ostream &os, Node*Head) {
	print(Head);
	return os;
}

Node* merge(Node*Head1, Node*Head2) {
	//base
	if (Head1 == NULL)
		return Head2;
	if (Head2 == NULL)
		return Head1;

	Node*SubHead;
	Node*Head;
	if (Head1->data <= Head2->data) {
		Head1->next = merge(Head1->next, Head2);
		SubHead = Head1;
	}
	else {
		Head2->next = merge(Head1, Head2->next);
		SubHead = Head2;
	}
	return SubHead;


}


int main() {
	Node *H1 = take_input();
	Node *H2 = take_input();

	cout << "LL1: " << H1;

	cout << "LL2: " << H2;

	Node *Merge_head = merge(H1, H2);

	cout << "After Merge sort: " << Merge_head;


	return 0;
}

