#include <iostream>

class Solution {
public:
    void dfs(int source , vector<bool> &vis , vector<int> path[])
    {
        if(vis[source])return;
        vis[source] = 1;
        for(auto child : path[source])
            dfs(child , vis , path);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<bool> vis(n , false );
    vector<int> path[n];
    for(auto edge : edges)
    {
        path[edge[0]].push_back(edge[1]);
        path[edge[1]].push_back(edge[0]);
    }
        dfs(source , vis , path);  
        return vis[destination];
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}