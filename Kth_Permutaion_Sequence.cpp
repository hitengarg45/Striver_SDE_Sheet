#include<bits/stdc++.h>
using namespace std;

//? Approach#1: Brute force
//? Create each permutation and then get the kth permutaion
//? Here we will create each permtutaion and then store them in a ds
//? TC - O(N! * N) -> Where N = length of the permutation and N! permutations are there and each to store each permutation extra N time is taken

//? Approach#2:
//? Now instead of creating each permutation
//? Get the idx of the element that will come at each place
//? Basically there are n positions and we have to get which number will take each position
//? Therefore by using formulas we can achieve this
//? TC: O(N * N), where first N as we go from N to 1 and second N to erase from the string and push in the string

void helper(int n, int k, string &s, string &ans, vector<long> &fact){
    if(n == 1){
        ans.push_back(s[0]);
        return;
    }

    int div = fact[n] / n;
    int idx = (k - 1) / div;
    ans.push_back(s[idx]);
    s.erase(idx, 1);

    helper(n - 1, (k % div == 0) ? div : k % div, s, ans, fact);
}

string kthPermutation(int n, int k){
    string ans = "";
    vector<long> fact(n + 1, 1);
        
    for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    
    string s = "";
    for(int i = 1; i <= n; i++) s += (i + '0');

    helper(n, k, s, ans, fact);

    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;

    string ans = kthPermutation(n, k);

    cout << ans;
}