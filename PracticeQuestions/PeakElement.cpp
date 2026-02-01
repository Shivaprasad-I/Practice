#include<bits/stdc++.h>
using namespace std;
int peakElement(vector<int>& arr){
    //return index of peak element
    long int length = arr.size(); 
    if(length == 1) return 0;// first if condition will be accessing out of bound to prevent that returned here
    for(long int i = 0; i < length; i++){
        if(i == 0){
            if( arr[i] > arr[i+1]) return i;
        }
        else if( i == length - 1){
            if( arr[i-1] < arr[i]) return i;
        }
        else if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {-1};
    int peakIndex = peakElement(arr);
    cout << "Peak Element is at index : " << peakIndex << endl;
}
