#include <iostream>
#include <vector>
#include <set>

using namespace std;
int findKthLargest(vector<int> nums, int k) {
    set<int>s(nums.begin(),nums.end());
    nums.clear();
    nums.assign(s.begin(),s.end());
    for(int x:nums){
        cout<<x<<",";
    }
    cout<<endl;
    return nums.at(nums.size()-k);
}
int main() {
    vector<int> vec = {3,2,3,1,2,4,5,5,6};
    cout<<findKthLargest(vec,4);
}
