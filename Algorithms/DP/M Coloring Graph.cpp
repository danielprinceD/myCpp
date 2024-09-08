class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isPossible(int node , int col , vector<vector<int>> &graph , vector<int> &color)
    {
        for(int it : graph[node])
        if(color[it] == col)return false;
        return true;
    }
    
    bool solver(int node , vector<vector<int>> &graph , vector<int> &color , int n , int m)
    {
        if(node == n)return 1;
        for(int col=1;col<=m;col++)
        {
            if(isPossible(node , col , graph , color))
            {
                color[node] = col;
                if(solver(node + 1 , graph , color , n , m ))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
    
    
    bool graphColoring(bool g[101][101], int m, int n) {
        vector<int> color(n+1 , 0);
        vector<vector<int>> graph; 
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            if(g[i][j] == 1)
                temp.push_back(j);
            graph.push_back(temp);
        }
        return solver( 0 , graph , color , n , m);
    }
};