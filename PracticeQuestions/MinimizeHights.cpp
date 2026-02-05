#include<bits/stdc++.h>
using namespace std;

// int getMinDiff(vector<int>& arr, int k){
//     int min = arr[0];
//     int max = arr[0];
//     int s_max = max;
//     long k2 = 2 * k;
//     //find min and max elements
//     for(int i = 1; i < arr.size(); i++){
//         if(arr[i] < min) min = arr[i];
//         if(arr[i] > max) {
//             s_max = max;
//             max = arr[i];
//         }
//     }
//     int diff = max-min;
//     cout << "Max: " << max << " Min: " << min << endl;
//     if( diff > 0){
//         if(diff > k2){
//             cout << "diff(" << diff <<") - k2("<<k2<<"): " << diff-k2 <<  endl;
//             return diff - k2;
//         }
//         else if( diff == k2){
//             int s_diff = max - s_max;
//             if(s_diff > k){
//                 cout << "s_diff + k2: " << s_diff+k2 <<  endl;
//                 return s_max - max + k2;
//             }
//             else{
//                 cout << "s_diff: " << s_diff << endl;
//                 return s_diff;
//             }
//         }
//     }
//     cout << "diff: "<< diff;
//     return diff;
// }

int getMinDiff(vector<int>& arr, int k){
    int length = arr.size();
    sort(arr.begin(), arr.end());
    // cout << " Array: ";
    // for(auto i: arr) cout << i << " -> ";
    // cout << "end" << endl;

    int ans = arr[length - 1]-arr[0];
    for(int i = 0; i < length - 1; i++){
        int _min = min(arr[0]+k, arr[i+1] - k); //compare rite 
        int _max = max(arr[length-1]-k, arr[i] + k);
        // cout << "Min: " << _min << " Max: " << _max << " Ans: " << ans << endl;
        if((_max - _min) < ans){
            ans = _max - _min;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,5,8,10}; int k = 2; //output = 5
    // vector<int> arr = {3,9,12,16,20}; int k = 3; //output = 11
    // vector<int> arr = {1,2,5}; int k = 2; //output = 1
    // vector<int> arr = {1,3,5}; int k = 2; //output = 1
    // vector<int> arr = {1,2,3,5}; int k = 2; //output = 2
    // vector<int> arr = {1,4,5}; int k = 2; //output = 1
    // vector<int> arr = {2,4,3,9,9,10,9,7,1,2}; int k = 4; //output = 5
    int response = getMinDiff(arr, k);
    cout << "Response: " << response << endl;
}
