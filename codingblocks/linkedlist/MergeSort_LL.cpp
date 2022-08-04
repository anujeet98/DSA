//MERGE SORT IN ARRAY AND LL same O(NlogN)
//one difference the time to find mid pt in LL is O(n) while array is O(1)


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

Node* find_middle_LL(Node*Head) {
	Node*slow = Head;
	Node*fast = Head;

	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* merge(Node*Head1, Node*Head2) {
	//base
	if (Head1 == NULL && Head2 == NULL)
		return NULL;
	if (Head1 == NULL)
		return Head2;
	if (Head2 == NULL)
		return Head1;

	Node*SubHead;
	Node*Head;
	if (Head1->data <= Head2->data) {
		SubHead = merge(Head1->next, Head2);
		Head = Head1;
	}
	else {
		SubHead = merge(Head1, Head2->next);
		Head = Head2;
	}
	Head->next = SubHead;
	return Head;


}

Node* Merge_Sort_divide(Node*Head) {
	//base
	if (Head == NULL or Head->next == NULL)
		return Head;

	//split LL into middle; get head of 2 splited LL
	Node*Mid = find_middle_LL(Head);
	Node*LL_H1 = Head; //start
	Node*LL_H2 = Mid->next;

	Mid->next = NULL;

	//call MergeSort fun on 2 divided LL
	LL_H1 = Merge_Sort_divide(LL_H1);
	LL_H2 = Merge_Sort_divide(LL_H2);

	//merge 2 sorted LL
	return merge(LL_H1, LL_H2);
}


int main() {
	Node *Head = take_input();

	cout << "LL: " << Head;

	Head = Merge_Sort_divide(Head);

	cout << "After Merge sort: " << Head;


	return 0;
}

