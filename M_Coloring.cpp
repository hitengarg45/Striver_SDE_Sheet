//* https://takeuforward.org/data-structure/m-coloring-problem/

//* Example 1:
//* Input: 
//* N = 4
//* M = 3
//* E = 5
//* Edges[] = {
//*   (0, 1),
//*   (1, 2),
//*   (2, 3),
//*   (3, 0),
//*   (0, 2)
//* }

//* Output: true

#include<bits/stdc++.h>
using namespace std;

//? Approach#2: Backtracking
//? Traverse on each node 1 by 1, and try to give it a color by checking the possible colors it can take
//? Then move to the next node and try to give this node a color
//? Now if at point we are not able to give a color to node then we need to BACKTRACK
//? TC - O(M^N), where M = no. of colors and N = Number of nodes, In worst case Each node may have to be backtracked M times

bool isSafe2(unordered_map<int, vector<int>> &graph, int idx, int col, vector<int> &color){
    for(int i = 0; i < graph[idx].size(); i++){
        int v = graph[idx][i];
        if(color[v] == col) return false;
    }

    return true;
}

bool helper2(unordered_map<int, vector<int>> &graph, int n, int idx, int m, vector<int> &color){
    if(idx == n) return true;

    for(int col = 1; col <= m; col++){
        if(isSafe2(graph, idx, col, color)){
            color[idx] = col;
            if(helper2(graph, n, idx + 1, m, color)) return true;
            color[idx] = -1;
        }
    }

    return false;
}

bool mColoring2(vector<vector<int>> &edges, int m, int n, int e){
    unordered_map<int, vector<int>> graph;

    for(int i = 0; i < e; i++){
        int s = edges[i][0];
        int d = edges[i][1];

        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    
    vector<int> color(n, -1);

    return helper2(graph, n, 0, m, color);
}

//? Approach#1: Backtracking
//? Here also I am trying to give a color to a node
//? By selecting the possible colors it can take
//? After that I am going to the adjacent nodes(1 by 1 one), so see if we can give color to it
//? If DFS in direction of any of the adjacent nodes is not able to give color to the node
//? Then we BACKTRACK, give a new color to node and then again do the DFS for all the adjacent nodes
//? If all the adjacent nodes give true result, then we are good.

bool isSafe(unordered_map<int, vector<int>> &graph, int idx, int col, vector<int> &color){
    for(int i = 0; i < graph[idx].size(); i++){
        int v = graph[idx][i];
        if(color[v] == col) return false;
    }

    return true;
}

bool helper(unordered_map<int, vector<int>> &graph, int idx, int m, vector<int> &color){
    for(int col = 1; col <= m; col++){
        if(isSafe(graph, idx, col, color)){
            color[idx] = col;
            bool flag = true;
            for(int i = 0; i < graph[idx].size(); i++){
                int v = graph[idx][i];
                if(color[v] == -1){
                    flag = helper(graph, v, m, color);
                    if(!flag) break; 
                }
            }
            if(flag) return true;
            color[idx] = -1; 
        }
    }

    return false;
}

bool mColoring(vector<vector<int>> &edges, int m, int n, int e){
    unordered_map<int, vector<int>> graph;

    for(int i = 0; i < e; i++){
        int s = edges[i][0];
        int d = edges[i][1];

        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(!helper(graph, i, m, color)) return false;
        }
    }

    return true;
}

int main(){
    int n;
    int m;
    int e;

    cin >> n >> m >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    for(int i = 0; i < e; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    //* Approach#1:
    //* cout << mColoring2(edges, m, n, e);

    //* Approach#2:
    cout << mColoring2(edges, m, n, e);
}