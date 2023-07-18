#include<iostream>
#include<deque>
#include <algorithm>

using namespace std;
int main(){
    deque<int>dq={45,7,14,18,92};
    dq.push_front(54);
    cout<<"SIZE: "<<dq.size()<<endl;
    for(int x:dq){
        cout<<x<<",";
    }
    cout<<endl;
    sort(dq.begin(),dq.end());
    for(int x:dq){
        cout<<x<<",";
    }
    cout<<endl;
}
