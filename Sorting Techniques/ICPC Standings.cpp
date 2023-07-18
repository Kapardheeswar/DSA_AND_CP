//
// Created by kapar on 03-07-2023.
//
#include<bits/stdc++.h>
using namespace std;
int partition(vector<pair<string,int>>&teams,int start,int end){
    int i = start-1;
    int pivot = teams[end].second;
    for (int j = start; j < end; j++) {
        if(teams[j].second<pivot){
            i++;
            swap(teams[i],teams[j]);
        }
    }
    swap(teams[i+1],teams[end]);
    return i+1;
}
void quicksort(vector<pair<string,int>>&teams,int start,int end){
    if(start>=end){
        return;
    }
    int pivot = partition(teams,start,end);
    quicksort(teams,start,pivot-1);
    quicksort(teams,pivot+1,end);
}
int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    quicksort(teams,0,teams.size()-1);
    int badness=0;
    for (int i = 0; i < teams.size(); i++) {
        badness+= abs(i+1-teams[i].second);
    }
    return badness;
}
int main(){
    vector<pair<string, int>> vec = {
            {"WinOrBooze", 1},
            {"BallOfDuty", 2},
            {"WhoKnows", 2},
            {"BholeChature", 1},
            {"DCECoders", 5},
            {"StrangeCase", 7},
            {"WhoKnows", 7}
    };
    cout<<badness(vec);
}