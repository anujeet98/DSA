/*
Given a linked list of length N and an integer K , append the last K elements of a linked list to the front. Note that K can be greater than N.

Input Format
First line contains a single integer N denoting the size of the linked list.
Second line contains N space separated integers denoting the elements of the linked list.
Third line contains a single integer K denoting the number of elements that are to be appended.

Constraints
1 <= N <= 10^4
1 <= K <= 10^4

Output Format
Display all the elements in the modified linked list.

Sample Input
7
1 2 2 1 8 5 6
3
Sample Output
8 5 6 1 2 2 1
Explanation
Initially the linked list is
1→ 2→ 3 → 4 → 5 → 6→ null
and k = 2. After appending the last two elements to the front , the new linked list looks like
5→ 6→ 1→ 2→ 3 → 4 → null
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

//   |
// 1 2 3 4->5->head
// 2 //get K+1 element from end ie 3rd from end //use slow fast ptr method
// 4 5 1 2 3


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

void LL_K_append(Node*&Head, int K, int N) {
	if (K == 0)
		return;
	Node*curr = Head;
	int x = 1;
	while (x <= N - K - 1) {
		curr = curr->next;
		x++;
	}
	Node*last = curr;
	curr = curr->next;
	last->next = NULL;
	Node*new_head = curr;

	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = Head;

	//update head
	Head = new_head;

}

int main() {
	int N, K;
	cin >> N;
	int i = 0;
	int node_val;
	Node*Head = NULL;

	while (i < N) {
		cin >> node_val;
		insertAtEnd(Head, node_val);
		i++;
	}

	cin >> K;
	LL_K_append(Head, K % N, N);

	//print
	Node*curr = Head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}

	return 0;

}