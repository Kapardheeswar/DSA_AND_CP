//
// Created by kapar on 08-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct node {
    int data;
    node *next;
};
typedef node *lptr;

lptr findend(lptr l) {
    if (l->next == NULL) {
        return l;
    }
    findend(l->next);
}

void addend(lptr &l, int data) {
    if (l == NULL) {
        l = new(node);
        l->data = data;
        l->next = NULL;
        return;
    }
    lptr e, f;
    e = new(node);
    e->data = data;
    e->next = NULL;
    f = findend(l);
    f->next = e;
    return;
}

void printList(lptr l) {
    if (l->next == NULL) {
        cout << l->data << endl;
        return;
    }
    cout << l->data << "-->";
    printList(l->next);
}

lptr findElementPointer(lptr l, int key) {
    if (l->data == key) {
        return l;
    }
    findElementPointer(l->next, key);
}

void insertAfterKey(lptr &l, int key, int data) {
    lptr e, f;
    e = new(node);
    e->data = data;
    e->next = NULL;
    f = findElementPointer(l, key);
    e->next = f->next;
    f->next = e;
    return;
}

lptr reverseLinkedList(lptr head) {
    if (head == NULL or head->next == NULL) {
        return head;
    }
    lptr smallHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

lptr iterativeReversing(lptr head) {
    lptr prev = NULL;
    lptr curr = head;
    lptr temp;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
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
        else{
            head->next = temp;
        }
    }
    return prev;
}

int main() {
    lptr l = NULL;
    for (int i = 0; i < 10; i++) {
        addend(l, i);
    }
    printList(l);
    insertAfterKey(l, 3, 10);
    printList(l);
    lptr r = reverseLinkedList(l);
    printList(r);
    lptr ir = iterativeReversing(r);
    printList(ir);
    lptr kr = kReverse(ir, 3);
    printList(kr);
    lptr np = NULL;
    for (int i = 0; i < 5; i++) {
        addend(np,i+1);
    }
    lptr knp = kReverse(np,3);
    printList(knp);
}