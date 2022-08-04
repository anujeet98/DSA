#include<iostream>
using namespace std;

class node {
public:
	int data;
	node *next;

	//constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtHead(node* &Head, int data) {
	if (Head == NULL) {
		Head = new node(data);//******WHY LL DYNAMICALLY ALLOCATED AND NOT STAICALLY, because STATIC ALLOCATION IS FLUSHED/destroyed ONCE OUT OF SCOPE, So DYNAMIC ALLOCATION USED in LL
		return;
	}

	node* n = new node(data);
	n->next = Head;
	Head = n;
}

node* take_input() {
	int n;
	cin >> n;
	node*head = NULL;
	while (n != -1) { //while(cin>>n)   : to take input from file till end of the file
		insertAtHead(head, n);
		cin >> n;
	}
	return head;
}

void print(node* head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

ostream& operator<<(ostream &os, node *Head) {
	print(Head);
	return os;
}


istream& operator>>(istream &is, node*&head) {
	head = take_input();
	return is;
}

node* reverse(node*head) {
	node*prev = NULL;
	node*curr = head;

	while (curr != NULL) {
		//store next of curr before delinking
		node*temp = curr->next;
		//delink and make curr next to prev
		curr->next = prev;
		//update/move curr to temp(actual next)
		//update prev to curr
		prev = curr;
		curr = temp;
	}

	//once done update the head and return
	head = prev;
	return head;
}

int main() {
	node *head;
	cin >> head;

	cout << "ll before" << endl;

	cout << head;

	cout << "ll after reverse" << endl;

	head = reverse(head);
	cout << head;

}



