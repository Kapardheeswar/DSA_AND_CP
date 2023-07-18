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