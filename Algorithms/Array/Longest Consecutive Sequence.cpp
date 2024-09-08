#include<bits/stdc++.h>
using namespace std;

void brute(int n , vector<int> &v)
{
    auto linear_search = [&](int ele)->bool
    {
        for(int i=0;i<n;i++)
            if(v[i] == ele)
                return true;
        return false;
    };
    int longest = 1;
    for(int i=0;i<n;i++)
    {
        int x = v[i] + 1;
        int count = 1;
        while(linear_search(x))
        {
            x++;
            count++;
        }
        longest = max(count , longest);
    }
    cout<<longest;
    
    // T -> O(N^3)
    // S -> O(1)
    
}

void better(int n , vector<int> &v)
{
    sort(v.begin() , v.end());
    int longest = 1 , cur_count = 0 , last_min = -1e9;
    for(int i : v)
    {
        
        if(i-1 == last_min)
        {
            cur_count++;
            last_min = i;
        }
        else if(last_min != i){
            last_min = i;
            cur_count = 1;
        }
        longest = max(longest , cur_count);
    }
    cout<<longest;
    
    // T -> O(N-logN)
    // S -> O(1)
    
}

void optimal(int n , vector<int> &v)
{
    unordered_set<int> st;
    for(auto it : v)
        st.insert(it);
    
    int longest = 1;
    for(auto it : st)
    {
        if(st.find(it-1) == st.end())
        {
            int count = 1;
            int x = it + 1;
            while(st.find(x) != st.end())
            {
                count+=1;
                x+=1;
            }
            longest = max(longest , count);
        }
    }
    cout<<longest;
    
    // T -> O(N + N)
    // S -> O(N)
    
}


int main(){
    vector<int> v({102 , 4 , 100 , 1 , 101 , 3 , 3 , 3, 2 , 1 , 1});
    optimal(v.size() , v);
}