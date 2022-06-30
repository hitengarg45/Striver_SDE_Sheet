//* https://takeuforward.org/data-structure/combination-sum-1/
//* We have to print the combinations having sum = k
//* All elements int the array are +ve, and unique
//* And we can use an element any number of times

#include<bits/stdc++.h>
using namespace std;

//? Approach#1: Using pick and not pick techinque
//? TC - O(2^N * K)

void printCombination(vector<int> &arr, int n, int idx, int sum, int k, vector<vector<int>> &ans, vector<int> &ds){
    if(sum > k) return;

    if(idx == n){
        if(sum == k) ans.push_back(ds);
        return;
    }

    //pick
    ds.push_back(arr[idx]);
    printCombination(arr, n, idx, sum + arr[idx], k, ans, ds);
    //not pick
    ds.pop_back();
    printCombination(arr, n, idx + 1, sum, k, ans, ds);
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int k;
    cin >> k;

    vector<vector<int>> ans;
    vector<int> ds;

    printCombination(arr, n, 0, 0, k, ans, ds);

    for(int i = 0; i < ans.size(); i++){
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++){
            if(j == ans[i].size() - 1) cout << ans[i][j];
            else cout << ans[i][j] << ",";
        }
        cout << "]" << endl;
    }
}