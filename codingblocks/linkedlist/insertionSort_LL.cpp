#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int d) {
		data = d;
		next = NULL;
		prev = NULL;
	}
};

void insert_at_end(Node *&Head, int data) {
	Node *n = new Node(data);
	if (!Head)
	{
		Head = n;
		return;
	}
	Node *curr = Head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = n;
	n->prev = curr;
}

void insertionSort(Node *Head) {
	if (Head == NULL or Head->next == NULL) {
		return;
	}
	Node* curr = Head->next;

	while (curr != NULL) {
		Node* j = curr->prev;
		int key = curr->data;
		while (j != NULL and key < j->data) {
			j->next->data = j->data;
			j = j->prev;
		}
		if (j == NULL)
			Head->data = key;
		else
			j->next->data = key;

		curr = curr->next;
	}
}


int main() {
	int n;
	cin >> n;
	int val;
	Node *Head = NULL;
	for (int i = 0; i < n; i++) {
		cin >> val;
		insert_at_end(Head, val);
	}
	insertionSort(Head);
	Node *curr = Head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}


	return 0;
}