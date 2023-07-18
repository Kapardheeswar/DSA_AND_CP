#include<bits/stdc++.h>

using namespace std;

int searchChar(vector<char> v, char k, int index) {
    for (int i = 0; i < v.size(); i++) {
        if (k == v.at(i) && i != index) {
            return 1;
        }
    }
    return 0;
}

int firstUniqChar(string s) {
    vector<char> v;
    for (int i = 0; i < s.length(); ++i) {
        v.push_back(s[i]);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << ",";
    }
    cout << endl;
    for (int i = 0; i < v.size(); ++i) {
        int isNotUnique = searchChar(v, v.at(i), i);
        if (isNotUnique == 0) {
            return i;
        }
    }
    return -1;
}


int main() {
    string s;
    cin >> s;
    cout<<firstUniqChar(s);
}
