//
// Created by kapar on 11-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct node {
    int data;
    node *right = NULL;
    node *left = NULL;
};
typedef node *btptr;

btptr createBT(btptr &t) {
    int k;
    cin >> k;
    if (k == -1) return NULL;
    t = new node;
    t->data = k;
    t->left = createBT(t->left);
    t->right = createBT(t->right);
    return t;
}

btptr createBTWithVector(btptr &t, vector<int> v, int &i) {
    if (v[i] == -1) {
        i++;
        return NULL;
    }
    t = new node;
    t->data = v[i];
    i++;
    t->left = createBTWithVector(t->left, v, i);
    t->right = createBTWithVector(t->right, v, i);
    return t;
}

void inorder(btptr s) {
    if (s == NULL) return;
    cout << s->data << " ";
    inorder(s->left);
    inorder(s->right);
}

bool areBothTreesEqual(btptr t1, btptr t2) {
    if(t1==t2) return true;
    if (t1 == NULL and t2 == NULL) return false;
    if (t1 == NULL or t2 == NULL or t1->data != t2->data) return false;
    bool checkOriginality = areBothTreesEqual(t1->left, t2->right) and areBothTreesEqual(t1->right, t2->right);
    bool checkReality = areBothTreesEqual(t1->left, t2->right) and areBothTreesEqual(t1->right, t2->left);
    return checkOriginality or checkReality;
}
