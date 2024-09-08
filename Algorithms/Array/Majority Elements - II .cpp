#include<bits/stdc++.h>
using namespace std;


void brute(int n, vector<int> &v)
{
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(ans.size() == 0 || ans[0] != v[i])
        {
            int count = 0;
            for(int j=0;j<n;j++)
                if(v[i] == v[j])
                    count++;
            if(count > n/3 && ans.size() < 2)
                ans.push_back(v[i]);
        }
    }
    for(int i : ans)
        cout<<i<<" ";
        
    // T -> O(N^2)
    // S -> O(1)
        
}

void better(int n, vector<int> &v)
{
    map<int , int > mp;
    vector<int> ans;
    for(int i : v)
    {
        mp[i]++;
        if(mp[i] == (n/3) + 1)
            ans.push_back(i);
    }
    for(int it : ans)cout<<it<<" ";
    
    // T -> O(N)
    // S -> O(N)

}

void optimal(int n , vector<int> &v)
{
    int count_1 = 0 , count_2 = 0 , ele_1 , ele_2;
    for(int i=0;i<n;i++)
    {
        if(count_1 == 0 && v[i] != ele_2)
        {
            count_1 = 1;
            ele_1 = v[i];
        }
        else if(count_2 == 0 && v[i] != ele_1)
        {
            count_2 = 1;
            ele_2 = v[i];
        }
        else if(ele_1 == v[i])
            count_1++;
        else if(ele_2 == v[i])
            count_2++;
        else{
            count_1--;
            count_2--;
        }
    }
    count_1 = 0 , count_2 = 0;
    for(int it : v)
    {
        if(ele_1 == it)count_1++;
        if(ele_2 == it)count_2++;
    }
    vector<int> ans;
    
    if(count_1 > n/3)ans.push_back(ele_1);
    if(count_2 > n/3)ans.push_back(ele_2);
    
    for(int i : ans)cout<<i<<" ";
    
    // T -> O(N + N)
    // S -> O(1)
}


int main(){
    vector<int> v({1, 1 , 1, 3 , 3 ,  2 , 2 , 2});
    optimal(v.size() , v);
}