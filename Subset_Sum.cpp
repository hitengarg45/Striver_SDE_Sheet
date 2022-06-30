//* https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
//* The problem here is to return the individual sum of each subset

#include<bits/stdc++.h>
using namespace std;

void printSubsetSum(vector<int> &arr, int n, int idx, int sum, vector<int> &ans){
    if(idx == n){
        ans.push_back(sum);
        return;
    }

    //pick
    printSubsetSum(arr, n, idx + 1, sum + arr[idx], ans);
    //not pick
    printSubsetSum(arr, n, idx + 1, sum, ans);
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans;
    printSubsetSum(arr, n, 0, 0, ans);

    sort(ans.begin(), ans.end());

    for(int i : ans){
        cout << i << " ";
    }
}