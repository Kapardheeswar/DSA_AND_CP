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

void printAtLevel(btptr t, int level, int k, int target) {
    if (t == NULL) return;
    if (level == k and t->data != target) cout << t->data << " ";
    printAtLevel(t->left, level + 1, k, target);
    printAtLevel(t->right, level + 1, k, target);
}

void getLevel(btptr t, int level, int key, int &ans) {
    if (t == NULL) return;
    if (t->data == key) {
        ans = level;
    }
    getLevel(t->left, level + 1, key, ans);
    getLevel(t->right, level + 1, key, ans);
}

void findNodePointer(btptr t, int key, btptr &search) {
    if (t == NULL) return;
    if (t->data == key) search = t;
    findNodePointer(t->left, key, search);
    findNodePointer(t->right, key, search);
}

void getFromNonDescendents(btptr t, int target, int dist) {
    if (t == NULL) return;
    int ans = -1;
    getLevel(t, -1, target, ans);
    if (ans != -1) {
        int x = dist - ans - 2;
        printAtLevel(t, -1, x, target);
    }
    getFromNonDescendents(t->left, target, dist);
    getFromNonDescendents(t->right, target, dist);
}

void printNodesAtDistanceK(btptr t, int target, int dist) {
    getFromNonDescendents(t, target, dist);
    btptr targetPointer = NULL;
    findNodePointer(t, target, targetPointer);
    if (targetPointer != NULL) {
        printAtLevel(targetPointer, 0, dist, target);
    }
}

int main() {
    vector<int> v = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    vector<int> v1 = {1, 2, 4, -1, -1, 5, 7, -1, -1, 8, 9, -1, -1, 10, -1, -1, 3, -1, 6, -1, -1};
    vector<int> v2 = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};
    vector<int> v3 = {0, 2, -1, -1, 1, 3, -1, -1, -1};
    btptr s = NULL;
    int i = 0;
    s = createBTWithVector(s, v3, i);
    inorder(s);
    cout << endl;
    printNodesAtDistanceK(s, 3, 3);
}