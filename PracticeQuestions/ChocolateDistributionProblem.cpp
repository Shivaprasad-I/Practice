#include<bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> a, int m){
    int length = a.size();
    sort(a.begin(), a.end());
    int min_diff = a[length - 1] - a[0];

    for(int i = 0; i <= length - m; i++){
        // cout << "a["<<i<<"]: " << a[i] << " a["<<i+m-1<<"]: " << a[i+m-1] << endl;
        int diff = a[i+m-1]-a[i];
        if(diff < min_diff){
            min_diff = diff;
        }
    }
    return min_diff;
}

int main(){
    // vector<int> arr = { 1,2,3,4,1 }; int k = 3; //ans = 1
    // vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12}; int k = 5; //ans = 6
    // vector<int> arr = {7,3,2,4,9,12,56}; int k = 3; //ans = 2
    // vector<int> arr = {3,4,1,9,56}; int k = 5; //ans = 55
    vector<int> arr = {11,13,7,5,13,12}; int k = 4; //ans = 2
    const int response = findMinDiff(arr, k);
    cout << "Response: " << response << endl;
}
