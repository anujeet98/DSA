#include<iostream>
using namespace std;

class node {
public:
	int data;
	node *next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void insert(node*&Head, int data) {
	//create new node
	node*n = new node(data);
	node*temp = Head;

	if (temp != NULL)
	{
		//make next of n as head
		n->next = Head;
		//traverse till end node and update the end ptr to new created node
		while (temp->next != Head) {
			temp = temp->next;
		}
		temp->next = n;
	}
	else
		n->next = n; //make end point to new node, self loops;

	Head = n;
}


void print(node*head) {
	node*temp = head;
	if (temp != NULL)
		cout << temp->data << " ";
	temp = temp->next;
	while (temp != head) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	node* head = NULL;
	insert(head, 10);
	insert(head, 20);
	insert(head, 30);
	insert(head, 40);
	print(head);
	return 0;
}

