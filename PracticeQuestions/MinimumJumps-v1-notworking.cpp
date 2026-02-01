#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr){
    int sum = 0;
    int count = 0;
    int length = arr.size();
    if(arr[0] == 0) return -1;
    // while(sum < length -1){
    //     if(arr[sum] <= 0){
    //         return -1;
    //     }
    //     sum += arr[sum];
    //     count ++;
    // }
    int i = 0;
    while(i < length){
        count ++;
        unordered_map<int, int> map = 
        cout<< "Current Count: " << count<<endl;
        if(i + arr[i] >= length){
            return count;
        }
        int next_max_position = i + 1;
        int max = i+ arr[i];
        for(int j = i + 1; j < i + arr[i]; j++){
            int k = arr[j];
            if(j + k < length){
                if(arr[k] > 0 && k+arr[k] > max){
                    next_max_position = k;
                    max = k + arr[k];
                    cout << "Reached next Max" << max << endl;
                }
            }
            else{
                cout << "reched end" << endl;
                return count;
            }
        }
        i = next_max_position;
    }
    return count;
}
int main(){
    // vector<int> arr = {9, 10, 1, 2, 3, 4, 8, 0, 0, 0, 0, 0, 0, 0, 1};
    vector<int> arr = { 3, 4, 5, 1, 0, 1, 0, 1, 1};
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
