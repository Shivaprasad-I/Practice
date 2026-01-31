#include<bits/stdc++.h>
using namespace std;
vector<int> sumArray(vector<int>& arr, int target){
    vector<int> r_values;
    int startIndex = 0;
    int arrLength = arr.size();
    int endIndex = 0;
    int sum = arr[0];

    while(sum != target) {
        // cout << sum << " | this is the sum" << endl;
        // cout << startIndex << " - " << endIndex << " => " << arrLength << endl;
        if(sum < target && endIndex < arrLength -1){
            // cout << "smaller than" << endl;
            sum += arr[++endIndex];
        }
        else if(sum > target && startIndex < arrLength){
            // cout << "greater than" << endl;
            sum -= arr[startIndex++];
            // startIndex++;
        }
        else{
            break;
        }
    };
    if(sum != target){
        // r_values.push_back(-1);
        // return r_values;
        return vector<int>{ -1 };
    }
    // cout << startIndex << " - " << endIndex << endl;
    // r_values.push_back(++startIndex);
    // r_values.push_back(++endIndex);
    // cout << startIndex << " - " << endIndex << endl;
    // return r_values;
    return vector<int>{ ++startIndex, ++endIndex };
}
int main(){
    vector<int> arr = {1,2,3,7,5};
    int sum = 12;
    // vector<int> arr = {42,16,39,7,12,3,35};
    // int sum = 23;
    // vector<int> arr = {7,49,25,18,14,10,29,1,31,19};
    // int sum = 109;
    // vector<int> arr = {38, 22, 20, 12, 47, 23, 18, 13, 18, 47, 36, 42};
    // int sum = 174;
    // vector<int> arr = {12,18,5,11,30,5};
    // int sum = 69;
    // vector<int> arr = {26,3,28,7};
    // int sum = 52;
    vector result = sumArray(arr, sum);
    if(result.size() > 1){
        cout << result[0] << " - " << result[1] << endl;
    }
    else{
        cout << result[0] << endl;
    }
}

//After so many attemps finally all test cases passed.
