//* https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/

//* Examples:

//* Input: n = 4

//* Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

#include<bits/stdc++.h>
using namespace std;

//? Approach#1: Using Backtracking
//? We try to fill the each row of Grid
//? In each row at each idx we will try to Place the N Queen
//? For that we will check if the place is safe or not to place the queen
//? i.e if the column will have queen already there we will not place
//? If the diagonals have queen then also not place
//? After placing the queen in each row if we reach end then it is a valid combination
//? But Now if we are not able to place a Queen in a particular row, then BACKTRACK
//? So it will go to previous row and try to place the Q at new column
//? Then again move forward

//? This is called Backtracking -> As if we are unable to proceed forward, then it will go Back
//? In Normal Recursion it will go till the end no matter what, and there it decides if it is a valid solution or not
//? TC - O(N! * N)

//? Optimization: Instead of traversing and checking if the col or diagonals have the queen or not
//? Use Hasmaps -> One for marking the column
//? 1 for left diagonal and 1 for right diagonal
//? create 2 visited arrays of size 2 * n + 1
//? for left diagonals, idx = (n - 1) - (row - col)
//? for right diagonals, idx = row + col

bool isSafe(vector<string> &ds, int i, int j, int n){
    for(int x = 0; x <= i; x++){
        if(ds[x][j] == 'Q') return false;
    }

    for(int x = i, y = j; x >= 0 && y >= 0; x--, y--){
        if(ds[x][y] == 'Q') return false;
    }

    for(int x = i, y = j; x >= 0 && y < n; x--, y++){
        if(ds[x][y] == 'Q') return false;
    }

    return true;
}

void nQueens(int n, int idx, vector<string> &ds, vector<vector<string>> &ans){
    if(idx == n){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < n; i++){
        if(isSafe(ds, idx, i, n)){
            ds[idx][i] = 'Q';
            nQueens(n, idx + 1, ds, ans);
            ds[idx][i] = '.';
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<string>> ans;
    string s(n, '.');
    vector<string> ds(n, s);

    nQueens(n, 0, ds, ans);

    for(int i = 0; i < ans.size(); i++){
        cout << "[" << endl;
        for(int j = 0; j < ans[i].size(); j++){
            cout << "\"" << ans[i][j] << "\"" << endl;
        }
        cout << "]" << endl;
    }
}