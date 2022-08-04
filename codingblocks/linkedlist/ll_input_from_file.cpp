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

//LinkedList class (objec oriented approach)
/*
class LinkedList{

	node *head;
	node *tail;

public:
	LinkedList(){

	}
	void insert(int d){

	}
	.....
	.....

}
*/

//funutions (procedural programming)
// void build() {

// }
// void insert() {

// }


//PASSING NODE HEAD PTR BY REFERENCE, SO THAT HEAD STORES NEW UPDATED VALUE while returning
void insertAtHead(node* &Head, int data) {
	if (Head == NULL) {
		Head = new node(data);//******WHY LL DYNAMICALLY ALLOCATED AND NOT STAICALLY, because STATIC ALLOCATION IS FLUSHED/destroyed ONCE OUT OF SCOPE, So DYNAMIC ALLOCATION USED in LL
		return;
	}

	node* n = new node(data);
	//to acess data
	//dereference the pointer and use . operator OR use ->with pointer variable
	//(*n).next = head  OR   n->next = head
	n->next = Head;
	Head = n;

	//head not empty
	//create node and make ptr to curr head and update head


}

//method 2 : inistead of updating head in funtn , return head
node* take_input() {
	int n;
	node*head = NULL;
	while (cin >> n) { //while(cin>>n)   : to take input from file till end of the file
		insertAtHead(head, n);
	}
	return head;
}


void insertInMiddle(node*&head, int d, int pos) {
	if (head == NULL || pos == 0) {
		return insertAtHead(head, d);
	}

	//create
	//reach pos-1th position OR if pos>length reach till END
	node *curr = head;
	while (--pos && curr->next != NULL) {
		curr = curr->next;
	}
	//reached pos-1 position, now insert new node with data d at pos position
	node *n = new node(d);
	//make n ka next = pos-1 node(curr) ka next
	//make pos-1 node(curr) ka next = n
	n->next = curr->next;
	curr->next = n;
}

void insertAtTail(node *&Head, int d) {
	if (Head == NULL) {
		Head = new node(d);
		return;
		//OR
		//return insertAtHead(Head, d);
	}
	node *curr = Head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	//reached last element ; create new node and add it
	node *n = new node(d);

	n->next = curr->next;
	curr->next = n;

}

void deleteHead(node*&Head) {
	if (Head == NULL) {
		return;
	}
	//temp static variable will destroy auto after fun scope
	node*temp = Head->next;
	//now delete head
	delete(Head);
	Head = temp;
}


void deleteTail(node*&Head) {
	if (Head == NULL)
		return;
	//if one element need to delete and update head
	if (Head->next == NULL) {
		//means 1 element present ie equivalent to deleting from head
		return deleteHead(Head);
	}

	//else go to last-1 element and delete last element
	node*curr = Head;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	node*temp = curr->next;
	curr->next = temp->next;
	delete(temp);
}

void print(node* head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << endl;
}

void deleteInMiddle(node*&Head, int pos) {
	if (Head == NULL || pos == 0)
		return deleteHead(Head);
	node*curr = Head;
	while (--pos && curr->next->next != NULL)
		curr = curr->next;
	node*temp = curr->next;
	curr->next = temp->next;
	delete(temp);

	print(Head);
}

//linear search
bool search(node*Head, int key) {
	node*curr = Head;
	while (curr != NULL) {
		if (curr->data == key)
			return true;
		curr = curr->next;
	}
	return false;
}

bool searchRecursive(node*Head, int key) {
	if (Head == NULL)
		return false;
	if (Head->data == key)
		return true;
	return searchRecursive(Head->next, key);
}




int main() {
	//since not creating LL class so need to create variable to track head

	node *Head = take_input();
	print(Head);

	//node *Head = NULL;

	// insertAtTail(Head, 9);
	// insertAtHead(Head, 2);
	// insertAtHead(Head, 1);
	// insertAtHead(Head, 3);
	// insertAtHead(Head, 0);

	// print(Head);

	// insertInMiddle(Head, 13, 2);

	// insertAtTail(Head, 18);

	// print(Head);

	// deleteTail(Head);

	// print(Head);

	// deleteHead(Head);

	// print(Head);

	// // deleteInMiddle(Head, 1);
	// // deleteInMiddle(Head, 1);
	// // deleteInMiddle(Head, 1);
	// // deleteInMiddle(Head, 1);
	// // deleteInMiddle(Head, 1);
	// // deleteInMiddle(Head, 1);
	// if (search(Head, 12))
	// 	cout << "found" << endl;
	// else
	// 	cout << "not found" << endl;


	// if (searchRecursive(Head, 13))
	// 	cout << "found" << endl;
	// else
	// 	cout << "not found" << endl;



}

