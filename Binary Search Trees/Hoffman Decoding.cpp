//
// Created by kapar on 13-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node* left;
    node* right;
};
typedef node* btptr;
btptr createBT(btptr &t) {
    char k;
    cin >> k;
    if (k == '#') return NULL;
    t = new node;
    t->data = k;
    t->left = createBT(t->left);
    t->right = createBT(t->right);
    return t;
}
map<string,char>m;
void decode_huff(btptr root, string s) {
    if(root==NULL)return;
    if(root->left==NULL and root->right==NULL){
        m[s] = root->data;
        return;
    }
    decode_huff(root->left,s+"0");
    decode_huff(root->right,s+"1");
}
void getDecoded(string s){
    int i = 0;
    string str = "";
    while(i<s.length()){
        str += s[i];
        if(m[str]!='\0'){
            cout<<m[str];
            str = "";
        }
        i++;
    }
}
int main(){
    btptr s = NULL;
    s = createBT(s);
    decode_huff(s,"");
    getDecoded("1001011");
}