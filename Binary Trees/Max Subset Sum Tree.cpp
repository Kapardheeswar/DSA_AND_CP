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

pair<int, int> maxSubsetSum(btptr t) {
    // int,int are include node and exclude node respectively
    pair<int, int> p, left, right;
    if (t == NULL) {
        p.first = p.second = 0;
        return p;
    }
    left = maxSubsetSum(t->left);
    right = maxSubsetSum(t->right);
    p.first = t->data + left.second + right.second;
    p.second = max(left.second, left.first) + max(right.first, right.second);
    return p;
}
void printAtLevel(btptr t,int level,int k){
    if(t==NULL) return;
    if(level==k) cout<<t->data<<" ";
    printAtLevel(t->left,level+1,k);
    printAtLevel(t->right,level+1,k);
}
int main(){
    vector<int> v = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    btptr s = NULL;
    int i = 0;
    s = createBTWithVector(s, v, i);
    inorder(s);
    cout << endl;
    pair<int,int>p = maxSubsetSum(s);
    cout<<max(p.second,p.first)<<endl;
    printAtLevel(s,1,3);
}