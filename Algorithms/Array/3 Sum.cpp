#include<bits/stdc++.h>
using namespace std;


void brute(int n, vector<int> &v)
{
    set<vector<int>> st;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(v[i] + v[j] + v[k] == 0)
                {
                    vector<int> temp = {v[i] , v[j] , v[k]};
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    
    for(auto row : st)
    {
        for(int ele : row)cout<<ele<<" ";
        cout<<endl;
    }
        
    // T -> O(N^3)
    // S -> O(1)
        
}

void better(int n, vector<int> &v)
{
    set<vector<int>> st;
    for(int i=0;i<n;i++)
    {
        set<int> hashSet;
        for(int j=i+1;j<n;j++)
        {
            int third = -(v[i] + v[j]);
            if(hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {v[i] , v[j] , third};
                sort(temp.begin() , temp.end());
                st.insert(temp);
            }
            hashSet.insert(v[j]);
        }
    }
    
    vector<vector<int>> ans(st.begin() , st.end());
    
    for(auto row : ans)
    {
        for(int ele : row)
        cout<<ele<<" ";
        cout<<endl;
    }
    
    // T -> O(N^2 + NlogN)
    // S -> O(N)
    
    
}

void optimal(int n , vector<int> &v)
{
    vector<vector<int>> ans;
    
    sort(v.begin() , v.end() );
    
    for(int i=0;i<n;i++)
    {
        if(i > 0 && v[i] == v[i-1])continue;
        
        int j = i + 1 , k = n - 1;
        
        while( j < k )
        {
            int sum = v[i] + v[j] + v[k];
            if(sum < 0)j++;
            else if(sum > 0)k--;
            else {
                ans.push_back({v[i] , v[j] , v[k]});
                j++; k--;
                while(j < k && v[j] == v[j-1])j++;
                while(j < k && v[k] == v[k+1])k--;
            }
        }
    }
    
    for(auto row : ans)
    {
        for(int ele : row)
        cout<<ele<<" ";
        cout<<endl;
    }
    
    // T -> O(N logN) + O(N ^ 2)
    // S -> O(1)
    
}


int main(){
    vector<int> v({-1 ,0 , 0 , 0 , 1 , 2 , -1 , -4});
    optimal(v.size() , v);
}