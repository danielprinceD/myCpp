#include<bits/stdc++.h>
using namespace std;


void brute(int n, vector<int> &v, int target)
{
    set<vector<int>> st;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l = k+1;l<n;l++)
                {
                    if(v[i] + v[j] + v[k] + v[l] == target)
                    {
                        vector<int> temp = {v[i] , v[j] , v[k] , v[l]};
                        sort(temp.begin() , temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    
    for(auto row : st)
    {
        for(int ele : row)cout<<ele<<" ";
        cout<<endl;
    }
        
    // T -> O(N^4)
    // S -> O(N * 4)
        
}

void better(int n, vector<int> &v , int target)
{
    set<vector<int>> st;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            set<int> hashSet;
            for(int k=j+1;k<n;k++)
            {
                long long fourth = target - (v[i] + v[j] + v[k]);
                if(hashSet.find(fourth) != hashSet.end())
                {
                    vector<int> temp = {v[i] , v[j] , v[k] ,(int)fourth};
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
                hashSet.insert(v[k]);
            }
        }
    }
    
    vector<vector<int>> ans(st.begin() , st.end());
    
    for(auto row : ans)
    {
        for(int ele : row)
        cout<<ele<<" ";
        cout<<endl;
    }
    
    // T -> O(N^3 + NlogN)
    // S -> O(N^2) + O(N)
    
}

void optimal(int n , vector<int> &v, int target)
{
    vector<vector<int>> ans;
    
    sort(v.begin() , v.end());
    
    for(int i=0;i<n;i++)
    {
        if(i > 0 && v[i] == v[i-1])continue;
        
        for(int j=i+1;j<n;j++)
        {
            if(j > i+1 && v[j] == v[j-1])continue;
            
            int k = j + 1 , l = n - 1;
            
            while( k < l)
            {
                int sum = v[i] + v[j] + v[k] + v[l];
                if(sum < target)k++;
                else if(sum > target)l--;
                else {
                    ans.push_back({v[i] , v[j] , v[k] , v[l]});
                    k++; l--;
                    while(k < l && v[k] == v[k-1])k++;
                    while(k < l && v[l] == v[l+1])l--;
                }
            }
        }
    }
    
    for(auto row : ans)
    {
        for(int ele : row)
        cout<<ele<<" ";
        cout<<endl;
    }
    
    // T -> O(N logN) + O(N ^ 3)
    // S -> O(1)
    
}


int main(){
    vector<int> v({-1 ,0 , 0 , 0 , 1 , 2 , -1 , -4});
    optimal(v.size() , v , 1);
}