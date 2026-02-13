#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool twoSum(vector<int>& arr, int target){
    int length = arr.size();
    unordered_map<int, int> arr_set;
    for(int i : arr){
        if(arr_set.find(i) != arr_set.end()){
            arr_set[i] ++;
        }
        else{
            arr_set.insert({i, 1});
        }
    }
    for(int i: arr){
        int required = target - i;
        // cout << "required: " << required << " i: " << i << endl;
        if(arr_set.find(required) != arr_set.end()){
            if(required == i) {
                if(arr_set[required] <= 1) continue;
            }
            return true;
        }
    }
    return false;
}

int main(){
    // vector<int> arr = { 1,2,3,4,1 }; int k = 16;
    // vector<int> arr = {1,1}; int k = 2;
    vector<int> arr = {0,-1,2,-3,1}; int k = -2;
    const int response = twoSum(arr, k);
    cout << "Response: " << response << endl;
    return 0;
}
