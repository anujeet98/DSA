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


//DETECT LOOP IN LL

bool detect_Loop(Node*Head, Node*&meetNode) {
	Node*slow = Head;
	Node*fast = Head;
	//if no loop reach end or null and return false
	//elde if loop; No end/NULL will come instead fast and slow will meet sometime; return true
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			meetNode = slow;
			return true;
		}
	}
	return false;
}

void Remove_loop_ll(Node*Head, Node*meetNode_Ptr) {
	Node*Curr = Head;
	Node*prev = meetNode_Ptr;
	while (Curr != meetNode_Ptr) {
		Curr = Curr->next;
		meetNode_Ptr = meetNode_Ptr->next;
		if (Curr == meetNode_Ptr)
			prev->next = NULL;
		else
			prev = prev->next;
	}
}


int main() {
	Node *Head = take_input();

	Node*meetNode = NULL; //adding to find and use it for removal

	cout << "before creating loop: ";
	if (detect_Loop(Head, meetNode))
		cout << "loop detected" << endl;
	else
		cout << "no loop detected" << endl;


	//creating loop to test
	Node*curr = Head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = Head->next->next;


	//after creating loop test
	cout << endl << "after creating loop -> checking: ";
	if (detect_Loop(Head, meetNode)) {
		cout << "loop detected; slow/fast pointers meet at node: " << meetNode->data << endl;


		//after removal of loop
		//detect loop and printing loop
		cout << "loop detected -> loop removal fun call -> checking if loop exists after removal : ";
		Remove_loop_ll(Head, meetNode);   //loop removal fun call

		if (detect_Loop(Head, meetNode))
			cout << "loop detected" << endl;
		else
			cout << "no loop detected" << endl;

		cout << endl << "LL after removal of loop: " << Head;
	}
	else
		cout << "no loop detected" << endl;



	// cout << "LL: " << Head;

	// Head = Merge_Sort_divide(Head);

	// cout << "After Merge sort: " << Head;


	return 0;
}







/*
//codingblocks submission
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

				// head - Head pointer of the Linked List
				// Return a boolean value indicating the presence of cycle
				// If the cycle is present, modify the linked list to remove the cycle as well
bool floydCycleRemoval(Node *head)
{
    			// Code here
    bool loop_found=false;

    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL and fast->next != NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            loop_found=true;
            break;
        }
    }
    if(loop_found==false)
        return loop_found;

			    //remove loop and return true
			    //make slow point to Head
    Node*prev=fast;
    slow=head->next;
    fast=fast->next;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
        prev=prev->next;
    }
    prev->next=NULL;

    return true;
}



//*   You do not need to refer or modify any code below this.
//*   Only modify the above function definition.
//*	Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
//*	You do not even need to read or know about the code below.


void buildCycleList(Node *&head)
{
    unordered_map<int, Node *> hash;
    int x;
    cin >> x;
    if (x == -1)
    {
        head = NULL;
        return;
    }
    head = new Node(x);
    hash[x] = head;
    Node *current = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            current->next = hash[x];
            return;
        }
        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
}

void printLinkedList(Node *head)
{
    unordered_set<int> s;
    while (head != NULL)
    {
        if (s.find(head->data) != s.end())
        {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    buildCycleList(head);

    bool cyclePresent = floydCycleRemoval(head);
    if (cyclePresent)
    {
        cout << "Cycle was present\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}


*/
