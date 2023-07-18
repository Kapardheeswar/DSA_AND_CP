//
// Created by kapar on 11-07-2023.
//
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

btptr levelOrderBuild(btptr &t) {
    int k;
    cin >> k;
    queue<btptr> q;
    t = new node;
    t->data = k;
    q.push(t);
    while (!q.empty()) {
        btptr s = q.front();
        q.pop();
        int k1, k2;
        cin >> k1 >> k2;
        if (k1 != -1) {
            s->left = new node;
            s->left->data = k1;
            q.push(s->left);
        }
        if (k2 != -1) {
            s->right = new node;
            s->right->data = k2;
            q.push(s->right);
        }
    }
    return t;
}

void levelOrderPrint(btptr t) {
    if (t == NULL) return;
    queue<btptr> q;
    q.push(t);
    q.push(NULL);
    while (!q.empty()) {
        btptr s = q.front();
        q.pop();
        if (s != NULL) {
            cout << s->data << " ";
            if (s->left != NULL) {
                q.push(s->left);
            }
            if (s->right != NULL) {
                q.push(s->right);
            }
        } else {
            cout << "\n";
            if (!q.empty()) q.push(NULL);
        }
    }
}

int main() {
    btptr s = NULL;
    s=levelOrderBuild(s);
    levelOrderPrint(s);
}
// 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1