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
int getMidElement(lptr fast,lptr slow){
    if(fast->next->next==NULL or fast->next==NULL)
        return slow->data;
    return getMidElement(fast->next->next,slow->next);
}
int kthLastElement(lptr head,int k){
    lptr fast = head;
    lptr slow = head;
    int cnt = 0;
    while(cnt<k){
        fast = fast->next;
        cnt++;
    }
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}
int main(){
    lptr l = NULL;
    for (int i = 0; i < 8; i++) {
        addend(l,i+1);
    }
    cout<<getMidElement(l,l);
}