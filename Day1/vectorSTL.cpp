#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    vector<int>vec={91,2,5,3,47};
    for (int x:vec) {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<vec.front()<<endl;
    sort(vec.begin(),vec.end());
    for (int x:vec) {
        cout<<x<<" ";
    }
    cout<<endl;
}
