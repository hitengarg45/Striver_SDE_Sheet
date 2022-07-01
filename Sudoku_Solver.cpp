//* https://takeuforward.org/data-structure/sudoku-solver/
//* Given a sudoku grid complete the grid

//* Example 1

//* 5 3 . . 7 . . . .
//* 6 . . 1 9 5 . . . 
//* . 9 8 . . . . 6 .
//* 8 . . . 6 . . . 3
//* 4 . . 8 . 3 . . 1
//* 7 . . . 2 . . . 6
//* . 6 . . . . 2 8 .
//* . . . 4 1 9 . . 5
//* . . . . 8 . . 7 9

//* [["5","3","4","6","7","8","9","1","2"]
//* ["6","7","2","1","9","5","3","4","8"]
//* ["1","9","8","3","4","2","5","6","7"]
//* ["8","5","9","7","6","1","4","2","3"]
//* ["4","2","6","8","5","3","7","9","1"]
//* ["7","1","3","9","2","4","8","5","6"]
//* ["9","6","1","5","3","7","2","8","4"]
//* ["2","8","7","4","1","9","6","3","5"]
//* ["3","4","5","2","8","6","1","7","9"]]


#include<bits/stdc++.h>
using namespace std;

//? Approach#1: Using Recursion
//? Rather than checking at each cell, just fill any number and in the last and check if the sudoku is valid or not
//? And if it is a valid sudoku then that is our ans

//? Approach#2: Using Backtrack
//? Check at each cell all the possible values we can have
//? After taking a good candidate, proceed next, if at any point we are not able to take a candidate then BACKTRACK
//? If we reach the end of sudoku, then We must return TRUE as to stop using other candidates
//? E.g in the previous row by taking 6 we are able to complete the last row and got our ans
//? So if didn't returned true, i.e used a void, then if will continue looking other candidates and find the ans
//? Which will override our current ans and also will not lead to an ans

bool isSafe(vector<vector<char>> &board, int x, int y, char val){
    for(int i = 0; i < 9; i++){
        if(board[x][i] == val) return false;
    }

    for(int i = 0; i < 9; i++){
        if(board[i][y] == val) return false;
    }

    int rs = 3 * (x / 3);
    int cs = 3 * (y / 3);

    for(int i = rs; i < rs + 3; i++){
        for(int j = cs; j < cs + 3; j++){
            if(board[i][j] == val) return false;
        }
    }

    return true;
}

bool solver(vector<vector<char>> &board, int x, int y){
    if(x == 9) return true;
    if(y == 9) return solver(board, x + 1, 0);

    if(board[x][y] != '.') return solver(board, x, y + 1);

    for(int val = 1; val <= 9; val++){
        if(isSafe(board, x, y, val + '0')){
            board[x][y] = val + '0';
            if(solver(board, x, y + 1)) return true;
            board[x][y] = '.';
        }
    }

    return false;
}

int main(){
    vector<vector<char>> board(9, vector<char>(9));

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
        }
    }

    solver(board, 0, 0);

    cout << "[";
    for(int i = 0; i < 9; i++){
        cout << "[";
        for(int j = 0; j < 9; j++){
            cout << "\"" << board[i][j] << "\"";
            if(j < 8) cout << ",";
        }
        cout << "]";
        if(i < 8) cout << endl;
    }
    cout << "]";
}