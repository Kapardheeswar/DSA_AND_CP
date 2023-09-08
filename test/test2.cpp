//
// Created by kapar on 08-09-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node *next;
};
typedef Node *lptr;

void printList(lptr t) {
    if (t == NULL) return;
    cout << t->data << " ";
    printList(t->next);
    return;
}
lptr reverseLinkedList(lptr head){
    if(head==NULL or head->next==NULL) return head;
    lptr smallHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}
int main() {
    lptr l = new Node;
    l->data = 1;
    l->next = NULL;
    lptr l1 = new Node;
    l1->data = 2;
    l1->next = NULL;
    lptr l2 = new Node;
    l2->data = 3;
    l2->next = NULL;
    lptr l3 = new Node;
    l3->data = 4;
    l3->next = NULL;
    lptr l4 = new Node;
    l4->data = 5;
    l4->next = NULL;
    l->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    printList(l);
    cout<<endl;
    lptr small = reverseLinkedList(l);
    printList(small);
}