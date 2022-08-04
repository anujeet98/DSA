//O(n) soln below
//other sol take 2 LL store odd an even numbers, join it and update head

/*
Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

Input Format
Enter N space separated Elements

Constraints
None

Output Format
Linked list with all the odd numbers before even numbers

Sample Input
5
1 2 2 2 1
Sample Output
1 1 2 2 2
*/

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node*next;
	//constr
	Node(int d) {
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

void even_odd(Node*&Head) {
	if (Head == NULL or Head->next == NULL)
		return;
	Node*curr = Head;
	Node*prev = Head;

	Node*dummyHead = new Node(-1);
	dummyHead->next = Head;
	Node*odd_ptr = dummyHead;

	while (curr != NULL) {
		if (curr->data % 2 != 0) {
			if (curr != odd_ptr->next) {
				prev->next = curr->next;
				//insert cur after oddptr;
				curr->next = odd_ptr->next;
				odd_ptr->next = curr;
				if (odd_ptr == dummyHead)
					Head = curr;
				curr = prev->next; //prev doesnt change as curr moves out
			}
			else {
				prev = curr;
				curr = curr->next;
			}
			odd_ptr = odd_ptr->next; // if odd and not in place: then move it and increase odd_ptr; if odd and in place then just increar odd_ptr
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
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

	even_odd(Head);

	//print
	Node*curr = Head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}

	return 0;

}