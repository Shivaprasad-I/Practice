#include<bits/stdc++.h>
using namespace std;

bool canAttend(vector<vector<int>> arr){
    int length = arr.size();
    
    //sort all the meetings based on the start time
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });

    //compare end time with the start time of the next meeting
    for(int i = 0; i < length-1; i++){
        // cout << "[ " << arr[i][0] << ", " << arr[i][1] << " ], [ " ;
        // cout << arr[i+1][0] << ", " << arr[i+1][1] << " ]"<< endl;
        if(arr[i+1][0] < arr[i][1] || arr[i+1] == arr[i]) return false;
    }
    return true;
}

int main(){
    // vector<vector<int>> arr = {{ 1,4 }, { 10,15 }, { 7,10 }}; //ans true
    // vector<vector<int>> arr = { {2,4}, {9,12}, {6,10} }; //ans false
    vector<vector<int>> arr = { {2,4}, {9,12}, {2,6} }; //ans false
    const bool response = canAttend(arr);
    cout << "OutPut: " << response << endl;
}
