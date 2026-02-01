#include<bits/stdc++.h>
using namespace std;
vector<int> leaders(vector<int> arr) {
    int n = arr.size();
    vector<int> peakElements;
    int lastPeakElement = arr[n-1];
    peakElements.push_back(arr[n-1]);
    for(int i = n - 2; i > -1; i--){
        if(arr[i] >= lastPeakElement){
            peakElements.insert(peakElements.begin(), arr[i]);
            lastPeakElement = arr[i];
        }
    }
    return peakElements;
}
int main() {
    vector<int> arr = { 4, 3, 2, 1};
    vector<int> out = leaders(arr);

    cout << "Leaders : ";
    for(int i = 0; i < out.size(); i++){
        cout << out[i] << " -> ";
    }
    cout << endl;
}
