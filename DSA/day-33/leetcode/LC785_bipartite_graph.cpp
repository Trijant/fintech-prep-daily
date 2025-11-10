#include<bits/stdc++.h>
using namespace std;

// topic: graph + dfs

class Solution {
private:
    bool dfs(vector<vector<int>> & graph,vector<int> & color,int node,bool c){
        if(color[node]!=-1){
            if(color[node]== c) return true;
            else return false;
        }
        color[node]=c;
        for(auto & adj:graph[node]){
            if(!dfs(graph,color,adj,c^1))return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        vector<int>color(size,-1);
        for(int i=0;i<size;i++){
            if(color[i]==-1 && !dfs(graph,color,i,false))return false;
        }
        return true;
    }
};
