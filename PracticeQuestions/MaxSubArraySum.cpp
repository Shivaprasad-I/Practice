#include<bits/stdc++.h>
#include <cstdint>
using namespace std;
int maxSubArraySum(vector<int>& arr){
        int length = arr.size();
        long int sum = arr[0];
        long int max_sum = INT64_MIN;
        int startIndex = 0;
        int endIndex = 0;

        while(true){
            if(startIndex >= length - 1 || endIndex >= length - 1){
                break;
            }
            if(arr[startIndex] < 0 && arr[startIndex] < sum ){
                if(startIndex < length){
                    sum -= arr[startIndex++];
                    if(sum > max_sum) max_sum = sum;
                    continue;
                }
            }
            if(endIndex < length - 1){
                if(sum > max_sum) max_sum = sum;
                sum += arr[endIndex];
                if(sum < arr[endIndex]) sum = arr[endIndex];
                endIndex++;
            }
            if(sum <= 0){
                if(sum > max_sum) max_sum = sum;
                sum = arr[endIndex];
                startIndex = endIndex;
            }
            cout << "Sum : " << sum  << " | MaxSum: " << max_sum << endl;
            cout << "startIndex : " << startIndex << " | endIndex : " << endIndex << " | endValue : " << arr[endIndex]<< endl;
        };
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
    vector<int> arr = {-5, 3, -1, -2, 13};
    // vector<int> arr = {-1,-3,-10,10};
    // vector<int> arr = {1, -20, 5, -5};
    // vector<int> arr = {-19, -22, -3,  12, -1, -26, -6, 23,  -11, 2, -26, -5, -16, 24, -2};
    int maxSum = maxSubArraySum(arr);
    cout << "maxSubArraySum : " << maxSum << endl;
}
