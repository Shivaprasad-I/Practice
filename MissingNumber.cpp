#include<bits/stdc++.h>
using namespace std;
int missingNum(vector<int>& arr){
        int n = arr.size();
        if(n <= 0) return 0;
        long long int sum = (n+2)*(n+1)/2;
        // cout<< "required Sum : " << sum;
        long long int arrSum = 0;
        int i = 0;
        while(i < n){
            arrSum += arr[i++];
        }
        // cout << "ArraySum : " << arrSum;
       return sum - arrSum; 
}
int main(){
    vector<int> arr = {1,2,3};
    int missingNumber = missingNum(arr);
    cout << "Missing Number is : " << missingNumber << endl;
}
