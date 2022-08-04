#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node*next;
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



Node* LL_Rev_K(Node*Head, int K) {
	if (Head == NULL or Head->next == NULL)
		return Head;

	int count = 1;

	Node*Tail = Head; //storing tail node to make its next as head returned from recursion

	Node*Curr = Head;
	Node*Prev = NULL;
	Node*N;

	//reverse the segment
	while (Curr != NULL and count <= K) {
		N = Curr->next;
		Curr->next = Prev;
		Prev = Curr;
		Curr = N;
		count++;
	}

	if (Curr != NULL)
		Tail->next = LL_Rev_K(Curr, K); //this will return rev_K list from n node to end; make the returned head as next of tail
	//Prev is current node(head of the segment) to be returned
	return Prev;
}

int main() {
	int N, K;
	cin >> N >> K;
	Node*Head = NULL;
	int node_val;
	while (N--) {
		cin >> node_val;
		insertAtEnd(Head, node_val);
	}

	//k_reversing algo
	Head = LL_Rev_K(Head, K);


	//printing after reversing
	Node*Curr = Head;
	while (Curr != NULL) {
		cout << Curr->data << " ";
		Curr = Curr->next;
	}

	return 0;
}
