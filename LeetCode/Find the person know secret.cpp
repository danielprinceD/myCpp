#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        priority_queue<pair<int ,int> , vector<pair<int , int>> , greater<pair<int , int >>> pq;
        vector<pair<int,int>> adj[n];
        for(auto &it : meetings)
        {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        vector<int> know(n);
        pq.push({0,0});
        pq.push({0 , firstPerson});
        while(!pq.empty())
        {
            auto [t,per] = pq.top();
            pq.pop();
            if(know[per])continue;
            know[per] = 1;
            for(auto &it : adj[per])
            {
                if(!(know[it.first]) && it.second >= t)
                    pq.push({it.second , it.first});
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
            if(know[i])
                ans.push_back(i);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {
        {3,1,3},  
        {1,2,2},  
        {0,3,3},  
    };
    vector<int>  find  = s.findAllPeople(4 ,v,3 );
    for(auto it : find)
        cout<<it<<" ";
}