//* https://takeuforward.org/data-structure/rat-in-a-maze/

//* Example 1:

//* Input:
//* N = 4
//* m[][] = {{1, 0, 0, 0},
//*         {1, 1, 0, 1}, 
//*         {1, 1, 0, 0},
//*         {0, 1, 1, 1}}

//* Output: DDRDRR DRDDRR

#include<bits/stdc++.h>
using namespace std;

//? Approach#1: Backtracking
//? Go in each and direction
//? If we are not able to proceed, Furthur the  BACKTRACK
//? Else we reached the end of maze save the Ans
//? TC: O(4^(N^2)), because there are total N^2 cells, and for each cell we can move in 4 directions

int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void ratInAMaze(vector<vector<int>> &maze, int n, int i, int j, vector<string> &ans, string &path){
    if(i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0 || maze[i][j] == -1) return;

    if(i == n - 1 && j == n - 1){
        ans.push_back(path);
        return;
    }

    for(int k = 0; k < 4; k++){
        int x = i + dir[k][0];
        int y = j + dir[k][1];

        if(k == 0) path.push_back('L');
        else if(k == 1) path.push_back('U');
        else if(k == 2) path.push_back('R');
        else path.push_back('D');

        int val = maze[i][j];
        maze[i][j] = -1;

        ratInAMaze(maze, n, x, y, ans, path);

        path.pop_back();
        maze[i][j] = val;
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }

    vector<string> ans;
    string path = "";

    ratInAMaze(maze, n, 0, 0, ans, path);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}