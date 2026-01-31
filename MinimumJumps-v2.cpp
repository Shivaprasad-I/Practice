// this uses loop inside loop need to get optimized version
#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr){
    int count = 0;
    if(arr[0] == 0) return -1;
    // vector< int> map;
    // for(int i = 0; i < arr.size(); i++){
    //     map.push_back(i+arr[i]);
    // }
    // int length = map.size();
    int length = arr.size();
    int current_pos = length - 1;
    // cout << "CurrentPos : " << current_pos << " Count: " << count << endl;
    while(count < length && current_pos > 0){
        for(int j = 0; j < length; j++){
            if(j + arr[j] >= current_pos){
                // cout << "Current Position: " << current_pos << " j: " << j << " count: " << count << endl;
                if(j >= current_pos){
                    // current position can never be reached 
                    return -1;
                }
                current_pos = j;
                break;
            }
        }
        // cout << "CurrentPos : " << current_pos << " Count: " << count << endl;
        count++;
    }
    return count;
}
int main(){
    vector<int> arr = {9, 10, 1, 2, 3, 4, 8, 0, 0, 0, 0, 0, 0, 0, 1}; //out 2
    // vector<int> arr = { 3, 4, 5, 1, 0, 1, 0, 1, 1}; //out 3 
    // vector<int> arr = {1,3,5,8,9,2,6,7,6,8,9}; // out 3
    // vector<int> arr = {1,2,0,0,0}; //out -1
    // vector<int> arr = {2,1,0,3,5,1,2}; //out -1
    //            i =   0, 1, 2, 3, 4, 5, 6, 7, 8
    //        range =   3, 5, 7, 4, 4, 6, 6, 8, 9
    //
    int count = minJumps(arr);
    cout << "count: " << count << endl;
}
// use hash map to solve this 
// store all the indexes and next index from that place range = index to next Index
// trace back from last position to first position using that range
// or go from the start and keep selecting items having maximum range
