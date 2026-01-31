#include<bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& arr){
    int length = arr.size();
    unordered_map<int, int> map;
    for(int i = 0; i < length; i++){
        if(map.find(arr[i]) == map.end()){
            map[arr[i]] = 1;
        }
        else{
            int count = map[arr[i]];
            map[arr[i]] = ++ count;
        }
    }
    vector<int> duplicateItems;
    for(auto i : map){
        if(i.second > 1){
            duplicateItems.push_back(i.first);
        }
    }
    return duplicateItems;
}
int main(){
    vector<int> arr = { 1,2,3,4,1 };
    vector<int> result = findDuplicates(arr);
    cout << "[ ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ", ";
    }
    cout << "]" << endl;
}
