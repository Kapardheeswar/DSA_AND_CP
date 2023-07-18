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

bool containsCycle(lptr head) {
    //Complete this function
    lptr slow = head;
    lptr fast = head;
    while (slow and fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
int main(){
    lptr l = NULL;
    for (int i = 0; i < 8; i++) {
        addend(l,i+1);
    }
    // Creating a cycle
    lptr temp = l;
    while(temp->data!=3){
        temp=temp->next;
    }
    lptr e = findend(l);
    e->next = temp;
    cout<<containsCycle(l);
}