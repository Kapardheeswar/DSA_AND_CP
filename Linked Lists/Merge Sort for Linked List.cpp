//
// Created by kapar on 08-07-2023.
//
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
lptr merge(lptr a,lptr b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    lptr c = NULL;
    if(a->data<b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}
lptr midPoint(lptr head){
    lptr slow = head;
    lptr fast = head->next;
    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
lptr mergeSort(lptr head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    lptr mid = midPoint(head);
    lptr a = head;
    lptr b = mid->next;
    mid->next=NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a,b);
}
int main(){
    lptr l=NULL;
    vector<int>v = {10,8,6,2,92,1};
    for (auto i:v) {
        addend(l,i);
    }
    printList(l);
    lptr sl = mergeSort(l);
    printList(sl);
}