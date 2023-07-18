#include<bits/stdc++.h>

using namespace std;

int zeroCount(vector<int> v) {
    int zeroCount = 0;
    for (int x: v) {
        if (x == 0) {
            zeroCount++;
        }
    }
    return zeroCount;
}

int maximumScore(int a, int b, int c) {
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    cout << v.size() << endl;
    for (int x: v) {
        cout << x << ",";
    }
    int score=0;
    while (zeroCount(v) < 2) {
        sort(v.begin(), v.end(), [](int a, int b) -> bool { return a > b; });
        v.at(0)-=1;
        v.at(1)-=1;
        score++;
    }
    return score;
}

int main() {
    cout<<maximumScore(2, 4, 6);
}
