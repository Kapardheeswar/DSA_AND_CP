#include <bits/stdc++.h>
using namespace std;
string addBigInteger(string str1, string str2)
{
    deque<int> num1;
    for (int i = 0; i < str1.length(); i++)
    {
        int k = CharToInt(str1[i]);
    }
}
int main()
{
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    string answer = addBigInteger(s1, s2);
    cout << answer << endl;
    return 0;
}