#include<bits/stdc++.h>
#include <cstdint>
using namespace std;
int maxSubArraySum(vector<int>& arr){
        int length = arr.size();
        long int sum = arr[0];
        long int max_sum = INT64_MIN;

        for(int i = 1; i < length; i++){
            max_sum = max(sum, max_sum);
            if(sum < 0){
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }
        }
        if(sum > max_sum) return sum;
        else return max_sum;
}
// there are few issue int this approach 
// 1st sum and max_sum are not utilized properly for comparision
// 2nd startIndex will not increament if it hits first positive integer
// Ex: {1, -20, 5, -5}
// 3rd loop will stop as soon as endIndex hits the last position leading to lower sum value
// Ex: {-1,-3,-2,0,3}
int main(){
    // vector<int> arr = {-5, 3, -1, -2, 13};
    // vector<int> arr = {-1,-3,-10,10};
    // vector<int> arr = {1, -20, 5, -5};
    vector<int> arr = {-1, 21, -4, 5, -5};
    // vector<int> arr = {-19, -22, -3,  12, -1, -26, -6, 23,  -11, 2, -26, -5, -16, 24, -2};
    int maxSum = maxSubArraySum(arr);
    cout << "maxSubArraySum : " << maxSum << endl;
}
