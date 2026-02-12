#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b){
    vector<int> result;
    unordered_set<int> set;

    int max_length = a.size() + b.size();

    result.reserve(max_length);
    set.reserve(max_length);

    // for(int i: a){
    //     if(set.find(i) == set.end()){
    //         set.insert(i);
    //         result.push_back(i);
    //     }
    // }
    // 
    // for(int i: b){
    //     if(set.find(i) == set.end()){
    //         set.insert(i);
    //         result.push_back(i);
    //     }
    // }

    for(int i: a){
        if(set.insert(i).second){ //returns weather insert happend or not
            result.push_back(i);  // if false then entry already exists
        }
    }
    
    for(int i: b){
        if(set.insert(i).second){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    vector<int> a = { 1,2,3,4,1 }; vector<int> b = { 1,2,3,4,1 }; //ans: [ 1, 2, 3, 4 ]
    // vector<int> a = {1,2,3,2,1}; vector<int> b = {3,2,2,3,3,2}; //ans:[ 1, 2, 3 ]
    // vector<int> a = {1,2,3}; vector<int> b = {4,5,6}; //ans:[ 1, 2, 3, 4, 5, 6 ]
    // vector<int> a = {1,2,1,1,2}; vector<int> b = {2,2,1,2,1}; //ans:[ 1, 2, 3, 4, 5, 6 ]
    const vector<int> response = findUnion(a, b);
    cout << "[ ";
    for(int i = 0; i < response.size(); i++){
        if(i == response.size() -1){
            cout << response[i] << " ]" << endl;
        }
        else{
            cout << response[i] << ", ";
        }
    }
}
