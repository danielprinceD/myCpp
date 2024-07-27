#include <bits/stdc++.h>
using namespace std;

unordered_map<char , int> dijkstra( char src ,unordered_map<char , vector<pair<char , int>>>  &mp , int size)
{
    unordered_map<char , int> dist;
    priority_queue<pair<int , char> , vector<pair<int , char>> , greater<pair<int , char>>> pq;
    pq.push({0 , src});
    while(!pq.empty())
    {
        int curr_dis = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
        if(dist[curr_node])continue;
        
        dist[curr_node] = curr_dis;
        
        for(auto it : mp[curr_node])
        {
            int newDist = curr_dis + it.second;
            pq.push({newDist , it.first});
    
        }
        
    }
    return dist;
}


int solver( string &src , string &tar , unordered_map<char , vector<pair<char , int>>> &mp )
{
    unordered_map<char , unordered_map<char , int>  >path_map;
    for(int i=0;i<src.length();i++)
        path_map[src[i]] = dijkstra( src[i] , mp , tar.length());
    
    int res = 0;
    for(int i=0;i<src.length();i++)
    {
        if(src[i] != tar[i])
        {
            if(! path_map[src[i]][tar[i]])return -1;
            res += path_map[src[i]][tar[i]];
        }
    }
        
    return res;
}

int main()
{
    string src = "abcd" , tar = "acbe";
    char original[] = {'a','b','c','c','e','d'};
    char changed[] = {'b','c','b','e','b','e'};
    
    int cost[] = {2,5,5,1,2,20};
    int size = sizeof(cost)/sizeof(int);
    unordered_map<char , vector<pair<char , int>>> mp;
    for(int i=0;i<size;i++)
        mp[original[i]].push_back({changed[i] , cost[i]});
    
    cout<<solver(src , tar , mp);
    
    return 0;
}