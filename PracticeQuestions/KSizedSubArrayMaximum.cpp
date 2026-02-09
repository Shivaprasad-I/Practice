#include<bits/stdc++.h>
#include <deque>
#include <locale>
using namespace std;

//dumb shit you're not suppose to return the sum but the maximum out of 3
// vector<int> maxOfSubarrays(vector<int>& arr, int k){
//     int length = arr.size();
//     vector<int> returnValues;
//     int sum = 0;
//     for(int i = 0; i < k; i++){
//         sum += arr[i];
//     }
//     cout << sum << endl;
//     returnValues.push_back(sum);
//     for(int i = 0; i + k < length; i++){
//         sum -= arr[i];
//         sum += arr[i+k];
//         returnValues.push_back(sum);
//     }
//     return returnValues;
// }

//works but time complexity is O(n log k)
// vector<int> maxOfSubarrays(vector<int>& arr, int k){
//     int length = arr.size();
//     vector<int> values;
//     map<int, int> subarray;
//     for(int i = 0; i < length; i++){
//         auto item = subarray.find(arr[i]);
//         if(item != subarray.end()){
//             item -> second ++;
//         }
//         else{
//             subarray.insert({arr[i], 1});
//         }
//         if(i + 1 >= k){
//             values.push_back(subarray.rbegin() -> first);
//             auto obj = subarray[arr[i+1-k]];
//             if(obj > 1){
//                 subarray[arr[i+1-k]] -= 1;
//             }
//             else{
//                 subarray.erase(arr[i+1-k]);
//             }
//         }
//     }
//     return values;
// }

//even though loop within a loop is used this will not result to O(n^2)
//BECAUSE:
//the values inserted is always once from the outer for loop time complexity: O(n) = constant
//and values accessed is always O(1) because we are always accessing the front element
//and since inner loop is looped to remove the inserted values 
//and visiting each elements only once in program cycle it results to O(n)
//so the time complexity is O(n) (for push) + O(n) (for pops) = O(n);
vector<int> maxOfSubarrays(vector<int>& arr, int k){
    const int length = arr.size();
    deque<int> container;
    vector<int> values;
    for(int i = 0; i < length; i++){
        if( !container.empty() && container.front() == i - k){
            container.pop_front();
        }

        while(!container.empty() && arr[container.back()] <= arr[i]){
            container.pop_back();
        }

        container.push_back(i);

        if(i >= k - 1){
            values.push_back(arr[container.front()]);
        }
    }
    return values;

}
int main(){
    // vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6}; int k = 3;
    vector<int> arr = {8,5,5,5,1,2,3}; int k = 3;
    const vector<int> response = maxOfSubarrays(arr, k);
    cout << "[ ";
    for(int i : response){
        cout << i << ", ";
    }
    cout << "]" << endl;
}
