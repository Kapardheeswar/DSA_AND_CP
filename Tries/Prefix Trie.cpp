//
// Created by kapar on 15-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct trieNode {
    char ch;
    unordered_map<char, trieNode *> m;
    bool isTerminal = false;
};
typedef trieNode *tptr;

tptr insert(tptr &t, string word) {
    tptr temp = t;
    for(char ch:word){
        if(temp->m.count(ch)==0){
            tptr n = new trieNode;
            n->ch = ch;
            n->isTerminal = false;
            temp->m[ch] = n;
        }
        temp = temp->m[ch];
    }
    temp->isTerminal = true;
    return t;
}

bool search(tptr t, string word,int i) {
    if(i==word.length() and t->isTerminal) return true;
    if(i<word.length() and t->m.count(word[i])!=0) return search(t->m[word[i]],word,i+1);
    return false;
}
int main(){
    vector<string>v={"apple","ape","no","news","not","never"};
    tptr t = new trieNode;
    t->ch = '\0';
    t->isTerminal = false;
    for (auto s:v) {
        t = insert(t,s);
        cout<<t->m[s[0]]->ch<<" ";
    }
    cout<<endl;
    cout<<search(t,"app",0);
}