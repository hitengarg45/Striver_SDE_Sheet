//* https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

//* Example 1:

//* Input:
//* 1
//* 6
//* god is now no where here
//* godisnowherenowhere

//* Output:
//* god is no where no where
//* god is no where now here
//* god is now here no where
//* god is now here now here

#include<bits/stdc++.h>
using namespace std;

//? Approach#1: Backtracking
//? Take a substring, is this substring is in the dictionary then add it to the ds
//? If at any point we are left with substring that is not present in the dictionary, then we BACKTRACK
//? Get a new substring and move forward, till full string has been traversed
//? TC: O(2^N * N) -> 2^N nodes gets created

void wordBreak(string &s, int n, int idx, unordered_set<string> &words, vector<string> &ans, string &ds){
    if(idx == n){
        ans.push_back(ds);
        return;
    }

    for(int i = idx; i < n; i++){
        int len = i - idx + 1;
        string sub = s.substr(idx, len);
        if(words.count(sub)){
            string newds = ds;
            if(ds != "") newds += " " + sub;
            else newds += sub;

            wordBreak(s, n, idx + len, words, ans, newds);
        }
    }
}

int main(){
    int k;

    cin >> k;

    vector<string> dictionary(k);
    for(int i = 0; i < k; i++){
        cin >> dictionary[i];
    }

    string s;
    cin >> s;

    unordered_set<string> words(dictionary.begin(), dictionary.end());

    vector<string> ans;
    string ds = "";

    wordBreak(s, s.length(), 0, words, ans, ds);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}