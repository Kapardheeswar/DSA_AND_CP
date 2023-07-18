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
map<int,vector<int>>m;
void getMap(btptr t,int distFromNode){
    if(t==NULL) return;
    m[distFromNode].push_back(t->data);
    getMap(t->left,distFromNode-1);
    getMap(t->right,distFromNode+1);
}
void printMap(){
    for(auto p:m){
        vector<int>nodes = p.second;
        for(auto i:nodes){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int> v = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    vector<int> v1 = {1,2,4,-1,-1,5,7,-1,-1,8,9,-1,-1,10,-1,-1,3,-1,6,-1,-1};
    vector<int>v2 = {3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,-1,8,-1,-1};
    btptr s = NULL;
    int i = 0;
    s = createBTWithVector(s, v, i);
    inorder(s);
    cout << endl;
    getMap(s,0);
    printMap();
}