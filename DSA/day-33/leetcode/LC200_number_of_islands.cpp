#include<bits/stdc++.h>
using namespace std;

// topic: graph + dfs

class Solution {
private:
    void dfs(vector<vector<char>>& grid,int i,int j,int &m,int &n,vector<vector<bool>>& visited){
        if(visited[i][j] ) return;
        else if(grid[i][j]=='0') {
            visited[i][j]=true;
            return;
        }
        visited[i][j]=true;
        if(j>0) dfs(grid,i,j-1,m,n,visited);
        if(j<m-1) dfs(grid,i,j+1,m,n,visited);
        if(i>0) dfs(grid,i-1,j,m,n,visited);
        if(i<n-1) dfs(grid,i+1,j,m,n,visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,m,n,visited);
                }
                visited[i][j]=true;
            }
        }
        return count;
    }
};

int main(){
    int n,m;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter m: ";
    cin>>m;
    vector<vector<char>> grid(n, vector<char>(m, '0'));
    cout<<"Enter elems: "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
        
    }
    Solution s;
    cout << "Count: " << s.numIslands(grid) << endl;
}