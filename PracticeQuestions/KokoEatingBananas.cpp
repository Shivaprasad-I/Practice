#include<bits/stdc++.h>
using namespace std;

//works but has time coplexity will be high specially the second loop when difference between largest and second largest
//another change added made second loop to run another binary search but still this is not optimized way 
// int kokoEat(vector<int> arr, int k){
//     int length = arr.size();
//     if (length <= 0) return -1;
//     sort(arr.begin(), arr.end());
//     int min = 0;
//     int max = length - 1;
//     int min_speed = INT_MAX;
//     int min_speed_pos = -1;
//     while(min <= max){
//         int mid = min + ((max-min)/2);
//         int time = mid;
//         bool time_not_met = false;
//         for(int i = mid; i < length; i++){
//             int cal = ceil((float) arr[i]/arr[mid]);
//             time += cal;
//             if(time > k){ 
//                 time_not_met = true;
//                 break;
//             }
//         }
//         if(time_not_met){
//             min = mid + 1;
//         }
//         else if(min_speed > mid){
//             min_speed = arr[mid];
//             min_speed_pos = mid;
//             max = mid - 1;
//         }
//     }
//     //use second binary function here 
//     if(min_speed_pos >= 0){
//         max = min_speed;
//         min = min_speed_pos > 0 ? arr[min_speed_pos - 1] : 1;
//         while(min <= max){
//             int mid = min + ((max - min)/2);
//             int time = min_speed_pos;
//             bool time_met = true;
//             for(int i = min_speed_pos; i < length; i++){
//                 int cal = ceil((float) arr[i]/mid);
//                 time += cal;
//                 if(time > k){ 
//                     time_met = false;
//                     break;
//                 }
//             }
//             if(!time_met){
//                 min = mid + 1;
//             }
//             else{
//                 min_speed = mid;
//                 max = mid - 1;
//             }
//         }
//     }
//     return min_speed;
// }
bool canFinish(vector<int>& arr, int speed, int time_r){
    int time = 0;
    for(int  i : arr){
        if(i <= speed){
            time++;
        }
        else{
            time += (i + speed - 1)/ speed;
        }
        if(time > time_r) return false;
    }
    return true;
}
int kokoEat(vector<int>& arr, int k){
    int min = 1;
    int max = arr[0];
    int min_speed = INT_MAX;
    for(int i : arr){
        if(i > max) max = i;
    }

    while(min <= max){
        int mid = min + ((max-min)/2);
        const bool isFinish = canFinish(arr, mid, k);
        if(!isFinish){
            min = mid + 1;
        }
        else{
            max = mid - 1;
            min_speed = mid;
        }
    }
    return min_speed;
}

int main(){
    vector<int> arr = {5,10,3}; int k = 4; //ans: 5
    // vector<int> arr = {5,10,15,20}; int k = 7; //ans: 10
    // vector<int> arr = {3,4}; int k = 10; //ans: 1
    const int response = kokoEat(arr, k);
    cout << "Minimum speed: " << response << endl;
}
