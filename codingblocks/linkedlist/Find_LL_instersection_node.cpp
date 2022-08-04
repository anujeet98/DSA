//https://online.codingblocks.com/app/player/239418/content/224388/5166/code-challenge
/*
Given two intersecting linked lists, write a function to find its point of intersection. If the lists do not intersect , return NULL.

Note : You are required to only write a single function. Do not modify / alter the remaining code.

This is a stub problem so you need not worry about taking input or displaying output. Only focus on the designated function.

Input Format
You are given a function which accepts head pointers of two linked lists.

Constraints
Your function should run in linear time.

Output Format
Return the intersection point node.

Sample Input
Consider these linked lists :
1 -> 2 -> 3  -> null
   ↗
4

o/p return node 2
(This is not the actual input that will be provided but rather a description of it)
*/



//BUILT TWO APPROACH : 1) M-1: use SET to store node O(m) time and space ;m=max_len(ll1,ll2)
// best                2) M-2: traverse bot and find lengths. find diff of length. traverse larger LL by diff node. move both LL together now to reach intersection together. time complex= O(2*m)==O(m) m=max_len(ll1,ll2)

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

// This function gets two arguments - the head pointers of the two linked lists
// Return the node which is the intersection point of these linked lists
// It is assured that the two lists intersect
Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    /*Code here*/
    set<Node*> visited;
    while (l1 != NULL and l2 != NULL) {
        if (l1 == l2)
            return l1;
        if (visited.count(l1))
            return l1;
        if (visited.count(l2))
            return l2;
        visited.insert(l1);
        visited.insert(l2);
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL) {
        if (visited.count(l1))
            return l1;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        if (visited.count(l2))
            return l2;
        l2 = l2->next;
    }
    return NULL;
}



/*
*
*
*   You do not need to refer or modify any code below this.
*   Only modify the above function definition.
*   Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*   You do not even need to read or know about the code below.
*
*
*
*/

Node *buildList(unordered_map<int, Node *> &hash)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *current = head;
    hash[x] = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        Node *n = new Node(x);
        hash[x] = n;
        current->next = n;
        current = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    unordered_map<int, Node *> hash;
    Node *l1 = buildList(hash);

    Node *l2 = NULL;
    int x;
    cin >> x;
    l2 = new Node(x);
    Node *temp = l2;

    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            temp->next = hash[x];
            break;
        }
        Node *n = new Node(x);
        temp->next = n;
        temp = n;
    }

    cout << "L1 - ";
    printLinkedList(l1);
    cout << "L2 - ";
    printLinkedList(l2);

    Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
    cout << "Intersection at node with data = " << intersectionPoint->data << endl;

    return 0;
}