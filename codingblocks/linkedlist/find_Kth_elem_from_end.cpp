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

node* reverseREC(node*head) {
	//base
	if (head == NULL or head->next == NULL)
		return head;

	node*curr = head;

	//store next of curr;
	node*temp = curr->next;
	//make curr next to null
	curr->next = NULL;
	//call recu funct on temp which will reverse it
	head = reverseREC(temp);
	//make temp next = curr
	temp->next = curr;

	return head;
}

node* find_middle_LL(node*Head) {
	node*slow = Head;
	node*fast = Head;

	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* find_Kth_from_end(node*Head, int k) {
	node*curr = Head;
	node*follower = Head;
	int i = 0;
	while (i != k) {
		curr = curr->next;
		i++;
	}
	//now curr and follower at k distance
	//move both till curr reaches end
	while (curr->next != NULL) {
		curr = curr->next;
		follower = follower->next;
	}
	return follower;

}




int main() {
	node *head;
	cin >> head;

	cout << "ll :" << endl;

	cout << head;

	int k;
	cin >> k;

	cout << "kth element from end: " << find_Kth_from_end(head, k)->data << endl;



}

