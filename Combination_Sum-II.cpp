//* https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/
//* We have to print the unique combinations having sum = k
//* All elements int the array are +ve, and non distinct
//* And we can use an element any only once

#include<bits/stdc++.h>
using namespace std;

//? Approach#0: Brute force
//? Making all the subsets having sum = k, using pick and not pick technique, and putting in the set to get unique subsets

//? Approach#1: Doing for loop to select element for each place
//? TC - O(2^N * K), why K because K is the avg length of each subset and while pushing in the ans it takes K time to copy

void printCombinationII(vector<int> &arr, int n, int idx, int sum, int k, vector<vector<int>> &ans, vector<int> &ds){
    //* Why -> Because when sum becomes k, we have our one subset
    //* This may not necessarily reach the end idx
    if(sum == k){
        ans.push_back(ds);

        return;
    }

    for(int i = idx; i < n && sum + arr[i] <= k; i++){
        if(i > idx && arr[i] == arr[i - 1]) continue;
        ds.push_back(arr[i]);
        printCombinationII(arr, n, i + 1, sum + arr[i], k, ans, ds);
        ds.pop_back();
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int k;
    cin >> k;

    //! Sorting is required to print unique combinations
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    vector<int> ds;

    printCombinationII(arr, n, 0, 0, k, ans, ds);

    for(int i = 0; i < ans.size(); i++){
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++){
            if(j == ans[i].size() - 1) cout << ans[i][j];
            else cout << ans[i][j] << ",";
        }
        cout << "]" << endl;
    }
}