//
// Created by kapar on 08-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node *next;
};
typedef Node *lptr;

lptr findend(lptr l) {
    if (l->next == NULL) {
        return l;
    }
    findend(l->next);
}

//void addend(lptr &l, int data) {
//    if (l == NULL) {
//        l = new(node);
//        l->data = data;
//        l->next = NULL;
//        return;
//    }
//    lptr e, f;
//    e = new(node);
//    e->data = data;
//    e->next = NULL;
//    f = findend(l);
//    f->next = e;
//    return;
//}
void printList(lptr l) {
    if (l->next == NULL) {
        cout << l->data << endl;
        return;
    }
    cout << l->data << "-->";
    printList(l->next);
}

int countNodes(lptr l) {
    if (l == NULL) return 0;
    return 1 + countNodes(l->next);
}

lptr kReverse(lptr head, int k) {
    lptr prev = NULL;
    lptr curr = head;
    lptr temp;
    int cnt = 1;
    while (curr != NULL and cnt <= k) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }
    if (temp != NULL) {
        int remainingNodes = countNodes(temp);
        if (remainingNodes >= 3)
            head->next = kReverse(temp, k);
        else {
            head->next = temp;
        }
    }
    return prev;
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
    cout << endl;
    lptr small = kReverse(l, 2);
    printList(small);
}