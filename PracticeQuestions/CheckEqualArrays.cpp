#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool checkEqual(vector<int>& a, vector<int>& b){
    int length = a.size();
    if(length != b.size()){
        return false;
    }

    unordered_map<int, int> map;

    for(int i: a){
        if(map.find(i) == map.end()){
            map.insert({i, 1});
        }
        else{
            map[i]++;
        }
    }
    for(int i: b){
        if(map.find(i) == map.end()){
            return false;
        }
        else if(map[i] > 1){
            map[i]--;
        }
        else{
            map.erase(i);
        }
    }
    if(map.size() == 0) return true;
    else return false;
}

int main(){
    // vector<int> arr = { 1,2,3,4,1 }; vector<int> brr = { 2,1,4,3,1 };
    vector<int> arr = { 1,2,3,5,1 }; vector<int> brr = { 2,1,4,3,1 };

    const int response = checkEqual(arr, brr);

    cout << "Is Equal: " << response << endl;
}
