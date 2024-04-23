#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n==1)
        {
            ans.push_back(0);
            return ans;
        }
        vector<int> deg(n);
        vector<int> path[n];
        for(auto e : edges)
        {
            deg[e[0]]++;
            deg[e[1]]++;
            path[e[0]].push_back(e[1]);
            path[e[1]].push_back(e[0]);
        }
        queue<int> leaf;
        for(int i=0;i<n;i++)if(deg[i]==1)leaf.push(i);
        while(n > 2)
        {
            int size = leaf.size();
            n -= size;
            while(size--)
            {
                int front = leaf.front();
                leaf.pop();
                for(auto f : path[front])
                {
                    deg[f]--;
                    if(deg[f]==1)leaf.push(f);
                }
            }
        }
        while(!leaf.empty())
        {
            int el = leaf.front(); leaf.pop(); ans.push_back(el);
        }
        return ans;
    }
};

int main()
{
    //[[3,0],[3,1],[3,2],[3,4],[5,4]]
    Solution s;
    vector<vector<int>> ed{
        {3, 0},
        {3 , 1},
        {3 , 2},
        {3 , 4},
        {5 , 4},
    };
    for(auto i : s.findMinHeightTrees(6 , ed)){
        cout<<i <<" "; 
    }

    return 0;
}
