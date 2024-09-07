#include <bits/stdc++.h>
using namespace std;

// NEXT PERMUTATION;

void print(auto &v)
{
    for(int i : v)
        cout<<i<<" ";
}

void swap(auto &v , int i , int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void allPossible(int i , vector<int> &v , vector<vector<int>> &ans)
{
    if(i == v.size())
    {
        ans.push_back(v);
        return;
    }
    for(int ind=i;ind<v.size();ind++)
    {
        swap(v , i , ind);
        allPossible(i+1 , v , ans);
        swap(v , i , ind);
    }
}

void brute(int n , vector<int> &v)
{
    auto temp = v;
    vector<vector<int>> ans;
    sort(temp.begin() , temp.end());
    allPossible(0 , temp , ans);
    int ans_i = -1;
    for(int i=0;i<ans.size();i++)
        if(ans[i] == v)
        {
            ans_i = i+1;
            break;
        }
    if(ans_i < 0)
        return;
    for(int i : ans[(ans_i) % ans.size()])
        cout<<i<<" ";
}

void better(int n , vector<int> &v)
{
    next_permutation(v.begin() , v.end());
    for(int i : v)
        cout<<i<<" ";
}

void optimal(int n , vector<int> &v)
{
    int ind = -1;
   for(int i=n-2;i>=0;i--)
   {
       if(v[i] < v[i+1])
       {
            ind = i;
            break;
       }
   }
    
    if(ind == -1)
    {
        reverse(v.begin() , v.end());
        print(v);
        return;
    }
    auto swap = [&](int i , int j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    };
    for(int i=n-1;i>ind;i--)
    {
        if(v[i] > v[ind])
        {
            swap(i , ind);
            break;
        }
    }
    
    reverse(v.begin()+ind+1 , v.end());
    print(v);
}



int main()
{
    vector<int> v = {3 , 2 , 1};
    optimal(v.size() , v);
}