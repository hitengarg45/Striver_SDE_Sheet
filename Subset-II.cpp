//* https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/
//* Print all the unqiue subsets

//* Example 1:
//* Input: array[] = [1,2,2]
//* Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

#include<bits/stdc++.h>
using namespace std;

//? Approach#1:
//? Getting all the subsets and storing all the unique
//? Means using pich/not pick approach get all the subsets and put them in the set 
//? This way only unique subsets will remain
//? TC - O(2^N * Klog(X)), where K is the avg length of a subset and X is the size of set

//? Approach#2
//? Rather than taking all the subsets we should add logic to eliminate the chances of duplicate subsets
//? And also as we need intermediate subsets also there no base check
//? TC - O(2^N * K) as if there are N unique elements, the n there will be 2^N subsets, Where K is the avg length of a subset
//? Whty K, because pushing a ds into ans will perform a copy operation that take O(K) time

void printUnique(vector<int> &arr, int n, int idx, vector<vector<int>> &ans, vector<int> &ds){
    //! Why no check because we need to get the intermediate generated subsets also
    //! Not the once in which last idx all the possible values have been taken
    ans.push_back(ds);

    //Choose for a particular place
    for(int i = idx; i < n; i++){
        if(i > idx && arr[i] == arr[i - 1]) continue;
        ds.push_back(arr[i]);
        printUnique(arr, n, i + 1, ans, ds);
        ds.pop_back();
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    //! Sorting is required to eliminate the condition of duplicate subsets
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    vector<int> ds;

    printUnique(arr, n, 0, ans, ds);

    for(int i = 0; i < ans.size(); i++){
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++){
            if(j == ans[i].size() - 1) cout << ans[i][j];
            else cout << ans[i][j] << ",";
        }
        cout << "]" << endl;
    }
}