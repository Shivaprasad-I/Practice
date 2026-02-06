#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s){
    bool isPalindrome = true;
    int length = s.size() - 1;
    int i = 0;
    while(i < length - i){
        if(s[i] == s[length - i]) {
            i++;
            continue;
        }

        isPalindrome = false;
        break;
    }
    return isPalindrome;
}

int main(){
    string arr = "abc";
    cout << isPalindrome(arr) << endl;
}
