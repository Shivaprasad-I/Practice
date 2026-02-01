#include<bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int> &val, vector<int> &wt){
    vector<int> weight = vector<int>();
    int length = wt.size();
    int sum = 0;
    for(int i = 0; i < length; i++){
        if(wt[i] <= W){

        }
    }
}
int main(){
    int w = 3;
    vector<int> val = {5, 3, 2};
    vector<int> wt = {1, 2, 3};
    int missingNumber = knapsack(w, val, wt);
    cout << "Missing Number is : " << missingNumber << endl;
}
