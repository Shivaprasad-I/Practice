#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

// vector<vector<int>> getPairs(vector<int>& arr){
//     int length = arr.size();
//     map<int, int> map;
//     for(int i = 0; i < length; i++){
//         if(map.find(arr[i]) != map.end()){
//              map[arr[i]] ++;
//         }
//         else{
//             map.insert({arr[i], 1});
//         }
//     }
//     vector<vector<int>> returnItem;
//     for(auto i = map.begin(); i != map.end();){
//         int complementValue = -1 * i -> first;
//         if( map.find(complementValue) != map.end() && i -> first != 0){
//             if(complementValue < i -> first){
//                 returnItem.push_back({complementValue, i->first});
//             }
//             else{
//                 returnItem.push_back({i->first, complementValue});
//             }
//             map.erase(complementValue);
//             i = map.erase(i);
//         }
//         else if(i->first == 0 && i->second > 1){
//             returnItem.push_back({0, 0});
//             i = map.erase(i);
//         }
//         else {
//             i++;
//         }
//     }
//     return returnItem;
// }

vector<vector<int>> getPairs(vector<int>& arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> returnValues;
    int left = 0;
    int right = arr.size() - 1;

    while(left < right){
        if(arr[left] + arr[right] == 0){
            returnValues.push_back({arr[left], arr[right]});
            left++;
            right--;
            // cout << "Left: " << left << " LeftValue: " << arr[left] << " Right: " << left << " RightValue: " << arr[right] << endl;
            while(left < right && arr[left - 1] == arr[left]){
                left++;
            }
            while(left < right && arr[right] == arr[right + 1]){
                right--;
            }
        }
        else if(arr[left] + arr[right] < 0){
            left ++;
        }
        else{
            right --;
        }
    }
    return returnValues;
}
int main(){
    // vector<int> arr = { -1, 0, 1, 2, -1, -4}; //output: [-1, 1]
    // vector<int> arr = {6,1,8,0,4,-9,-1,-10,-6,-5}; //output: [-6, 6], [-1, 1]
    vector<int> arr = {0,0,0}; //output: [0, 0]
    vector<vector<int>> output = getPairs(arr);
    for(int i = 0; i < output.size(); i++){
        auto values = output[i];
        cout << "[ " << values[0] << ", " << values[1] <<"]" << endl;
    }
}
