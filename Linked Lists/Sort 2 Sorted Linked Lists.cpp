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
int main(){
    lptr a=NULL;
    for (int i = 0; i < 5; i++) {
        addend(a,i+1);
    }
    printList(a);
    lptr b = NULL;
    for (int i = 6; i < 12; i++) {
        addend(b,i+1);
    }
    printList(b);
    lptr c = merge(a,b);
    printList(c);
}