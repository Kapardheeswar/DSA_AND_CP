//
// Created by kapar on 13-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
struct Car{
    string id;
    int x;
    int y;
    int getDist() const{
        return x*x+y*y;
    }
};
class CarCompare{
public:
    bool operator()(Car A,Car B){
        return A.getDist()<B.getDist();
    }
};
int main(){
    vector<Car>cars;
    string id;
    int x,y;
    cin>>id;
    while(id!=".."){
        cin>>x>>y;
        Car c;
        c.id = id;
        c.x = x;
        c.y = y;
        cars.push_back(c);
        cin>>id;
    }
    priority_queue<Car,vector<Car>,CarCompare>maxHeap(cars.begin(),cars.begin()+3);
    for (int i = 0; i < cars.size(); i++) {
        auto c = cars[i];
        if(c.getDist()<maxHeap.top().getDist()){
            maxHeap.pop();
            maxHeap.push(c);
        }
    }
    while (!maxHeap.empty()){
        cout<<maxHeap.top().id<<" ";
        maxHeap.pop();
    }
}