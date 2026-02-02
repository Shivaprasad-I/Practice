#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
// this will not work for vector<int> arr = {-7, 1,5,2,-4,3,0}; //out = 3
// int findEquilibrium(vector<int>& arr){
//     long totalsum = 0;
//     int length = arr.size();
//     if(length == 0) return -1;
//     for(int i = 0; i < length; i++){
//         totalsum += arr[i];
//     }
//
//     long halfSum = totalsum / 2;
//     int eqPoint = -1;
//     int i = 0;
//
//     while(i < length){
//         if(eqPoint == -1){
//             halfSum -= arr[i];
//             if(halfSum == 0){
//                 eqPoint = i + 1;
//                 i += 1;
//             }
//         }
//         else if(eqPoint > 0){
//             // cout << halfSum;
//             halfSum += arr[i];
//             cout << "Arr[i]: " << arr[i] << " HalfSum: " << halfSum << endl;
//         }
//
//         cout<< "Index: " << i << " HalfSum: " << halfSum << endl;
//         if(i == length - 1 && halfSum == totalsum / 2){
//             return eqPoint;
//         }
//         i++;
//     }
//     return -1;
// }

// this will break if sum values are repeated arr = { -1, 1, 1, -1}
// hashmap keys = { -1, 0, 1, 0 (this will override the first one) }
// int findEquilibrium(vector<int>& arr){
//     int length = arr.size();
//     if(length == 0) return -1;
//     unordered_map<long, int> sumMap;
//     long sum1 = 0;
//     
//     for(int i = 0; i < length; i++){
//         sum1 += arr[i];
//         sumMap.insert({sum1, i});
//     }
//
//     long sum2 = 0;
//     for(int i = length - 1; i > -1; i--){
//         sum2 += arr[i];
//         if(sumMap.find(sum2) != sumMap.end()){
//             if(sumMap[sum2] + 1 == i - 1){
//                 return i - 1;
//             }
//         }
//     }
//     return -1;
// }


int findEquilibrium(vector<int>& arr){
    int length = arr.size();
    long totalSum = 0;
    for(auto i : arr) totalSum += i;

    long leftHalfSum = 0;
    for(int i = 0; i < length; i++){
        totalSum -= arr[i];
        if(totalSum == leftHalfSum) return i; //this should resolve the issue I had in first approach
        leftHalfSum += arr[i];
    }
    return -1;
}
int main(){
    // vector<int> arr = {1,2,0,3}; //out = 2
    // vector<int> arr = {1,1,1,1}; //out = -1
    vector<int> arr = {-7, 1,5,2,-4,3,0}; //out = 3

    int response = findEquilibrium(arr);
    cout << "Equilibrium point: " << response << endl;
}
