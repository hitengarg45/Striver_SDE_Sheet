//* https://takeuforward.org/data-structure/palindrome-partitioning/
//* Partition string such that each substring is a palindrome
//* Example 1:

//* Input: s = “aab”

//* Output: [ ["a","a","b"], ["aa","b"] ]

#include<bits/stdc++.h>
using namespace std;

//? Approach#1:
//? Backtracking, Simple take a substring check if it is a valid candidate i.e a valid palindrome substring
//? Then add this valid palindrome to ds and go for the remaining string
//? TC - O(2^N * (K + K)), why 2^N e.g if every substring is palindrome
//? Then if we draw the recursion tree 2^N nodes are there
//? And to create a substring K time is taken where K is the avg length of a substring and another K to check if it is a palindrome

//? Approach#2: Same as above but with slight Optimization
//? Rather than check at each step if the string is palindrome or not -> because same string is getting checked multiple times
//? Precompute this
//? TC -  O(2^N * (K)) + O(N^2), here one operation of checking palindrome got removed, but N^2 time is taken to precompute

bool isPalindrome(string &s){
    int l = 0, r = s.length() - 1;
    while(l < r){
        if(s[l] != s[r]) return false;
        l++; r--;
    }

    return true;
}

void palindromePartition(string &s, int n, int idx, vector<vector<string>> &ans, vector<string> &ds){
    if(idx >= n){
        ans.push_back(ds);
        return;
    }

    for(int i = idx; i < n; i++){
        int len = i - idx + 1;
        string sub = s.substr(idx, len);
        if(isPalindrome(sub)){
            ds.push_back(sub);
            palindromePartition(s, n, idx + len, ans, ds);
            ds.pop_back();
        }
    }
}

void palindromePartition2(string &s, int n, int idx, vector<vector<string>> &ans, vector<string> &ds, vector<vector<bool>> &isPalindromeSet){
    if(idx >= n){
        ans.push_back(ds);
        return;
    }

    for(int i = idx; i < n; i++){
        int len = i - idx + 1;
        string sub = s.substr(idx, len);
        if(isPalindromeSet[idx][i]){
            ds.push_back(sub);
            palindromePartition2(s, n, idx + len, ans, ds, isPalindromeSet);
            ds.pop_back();
        }
    }
}

int main(){
    string s;
    cin >> s;

    int n = s.length();

    vector<vector<string>> ans;
    vector<string> ds;

    //* palindromePartition(s, n, 0, ans, ds);

    //* Precomputing the Palindromes
    vector<vector<bool>> isPalindromeSet(n, vector<bool>(n, true));

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if(s[i] == s[j]) isPalindromeSet[i][j] = isPalindromeSet[i + 1][j - 1];
            else isPalindromeSet[i][j] = false;
        }
    }

    palindromePartition2(s, n, 0, ans, ds, isPalindromeSet);

    for(int i = 0; i < ans.size(); i++){
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++){
            if(j == ans[i].size() - 1) cout << ans[i][j];
            else cout << ans[i][j] << ",";
        }
        cout << "]" << endl;
    }
}