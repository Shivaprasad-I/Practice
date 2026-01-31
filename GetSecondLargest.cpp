#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int getSecondLargest(int *arr, int n) {
    int secondLargest = -1;
    if(n > 0)
    {
        int firstLargest = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > firstLargest)
            {
                secondLargest = firstLargest;
                firstLargest = arr[i];
            }
            else if( arr[i] > secondLargest && arr[i] != firstLargest)
            {
                secondLargest = arr[i];
            }
        }
    }
    return secondLargest;
}
int main(){
    int arr[] = { 12, 35, 1, 10, 34, 1};
    int val = getSecondLargest( arr, 6);
    cout << val << endl;
    return 0;
}
