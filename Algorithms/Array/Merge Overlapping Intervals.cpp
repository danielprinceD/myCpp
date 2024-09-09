#include <bits/stdc++.h>
using namespace std;

void brute(int n , vector<pair<int , int >> &v)
{
    sort(v.begin() , v.end());
    vector<pair<int , int >> ans;
    for(int i=0;i<n;i++)
    {
        int start = v[i].first;
        int end = v[i].second;
        
        if(!ans.empty() && end <= ans.back().second )continue;
        
        for(int j=i+1;j<n;j++)
        {
            if(end >= v[j].first)
                end = max(end , v[j].second);
        }
        ans.push_back({start , end});
    }
    
    for(auto [f , s] : ans)
        cout<<f<<" "<<s<<endl;
    
    
    // T -> O(N * 2) + O(N-logN)
    // S -> O(N * 2);
    
    
}

void optimal(int n , vector<pair<int , int >> &v)
{
    vector<pair<int , int>>ans;
    
    sort(v.begin() , v.end());
    
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || ans.back().second < v[i].first )
            ans.push_back(v[i]);
        else {
            ans.back().second = max(v[i].second , ans.back().second);
        }
    }
    
    for(auto [f , s] : ans)
        cout<<f<<" "<<s<<endl;
    
}


int main()
{
    vector<pair<int,int>> v({
        {1 , 3},
        {2 , 6},
        {8 , 9},
        {9 , 11},
        {8 , 10},
        {2 , 4},
        {15 , 18},
        {16 , 17},
    });
    
    optimal(v.size() , v);
    return 0;
}