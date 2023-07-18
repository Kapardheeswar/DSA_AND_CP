#include<bits/stdc++.h>

using namespace std;

vector<int> decode(vector<int> encoded, int first) {
    int pre = first;
    vector<int> decode;
    decode.push_back(first);
    for (int i = 1; i < encoded.size()+1; ++i) {
        decode.push_back(pre ^ encoded.at(i-1));
        pre=decode.at(i);
    }
    return decode;
}

int main() {
    vector<int> encoded = {1, 2, 3};
    int first = 1;
    vector<int> vec = decode(encoded, first);
    for (int k: vec) {
        cout << k << ",";
    }
}
