//* https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/
//* Example 1: 

//* Input: arr = [1, 2, 3]

//* Output: 
//* [
//*   [1, 2, 3],
//*   [1, 3, 2],
//*   [2, 1, 3],
//*   [2, 3, 1],
//*   [3, 1, 2],
//*   [3, 2, 1]
//* ]

#include<bits/stdc++.h>
using namespace std;

//? Approach#1: Using for loop to put a number at each place
//? Mark the number as visited as the same number should not be inserted again
//? O(N! * N), N! factorial permuations and N time to insert then into ans array

//? Approach#2: Rather than using a visited arr ond pushing elements in ds
//? Each place can have elements from all the places
//? Means idx = 0, can have elements from 0 to n - 1
//? There swap the elements
//? TC - O(N! * N), N! permutations, N for for loop of swapping

void printPermutations(vector<int> &arr, int n, vector<vector<int>> &ans, vector<int> &ds, vector<bool> &visited){
    if(ds.size() == n){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ds.push_back(arr[i]);
            visited[i] = true;
            printPermutations(arr, n, ans, ds, visited);
            ds.pop_back();
            visited[i] = false;
        }
    }
}

void printPermutations2(vector<int> &arr, int n, int idx, vector<vector<int>> &ans){
    if(idx == n){
        ans.push_back(arr);
        return;
    }

    for(int i = idx; i < n; i++){
        swap(arr[idx], arr[i]);
        printPermutations2(arr, n, idx + 1, ans);
        swap(arr[idx], arr[i]);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> visited(n, false);

    //* Approach#1
    //* printPermutations(arr, n, ans, ds, visited);

    //* Approach#2
    printPermutations2(arr, n, 0, ans);

    for(int i = 0; i < ans.size(); i++){
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++){
            if(j == ans[i].size() - 1) cout << ans[i][j];
            else cout << ans[i][j] << ",";
        }
        cout << "]" << endl;
    }
}