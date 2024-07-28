#include <bits/stdc++.h>
using namespace std;

/*void dfs(int node , vector<int> adj[] ,stack<int> &st , bool vis[] )
{
    vis[node] = 1;
    for(int i : adj[node])
        if(!vis[i])
            dfs(i , adj , st , vis);
    
    st.push(node);
}*/

/*void topological_sort(vector<int> adj[] , int size)
{
    stack<int> st;
    bool vis[size];
    for(int i=0;i<size;i++)
        if(!vis[i])
        dfs(i , adj , st , vis);
        
    for( ; !st.empty() ; st.pop())
    {
        cout<<st.top()<<" ";
    }
}*/


void dfs(char node , unordered_map<char , vector<char>> &adj , stack<char> &st, bool vis[] )
{
    vis[node - 'a'] = 1;
    for(char c : adj[node])
    {
        if(!vis[c-'a'])
            dfs(c, adj , st , vis);
    }
    st.push(node);
}

string getAlienLanguage(vector<string> &dictionary, int k)
{
    stack<char> st;
    unordered_map<char , vector<char>> adj;
    for(int i=0;i<dictionary.size()-1;i++)
    {
        int s1 = 0 ,s2 = 0;
        while(s1 < dictionary[i].length() && s2 < dictionary[i+1].length())
        {
            if(dictionary[i][s1] != dictionary[i+1][s2])
            {
                adj[dictionary[i][s1]].push_back(dictionary[i+1][s2]);
                break;
            }
            s1++; s2++;
        }
    }
    
    bool vis[k];
    
    for(char a = 'a' ; a<'a'+k ; a++)
    {
        if(!vis[a-'a']) dfs(a , adj , st , vis);
    }
    string res = "";
    for(; !st.empty() ; st.pop())
        res+=st.top()<<" ";
    
    return res;
}

int main()
{
    vector<string> v({"bbcc" , "abcd" , "abca" , "cab" , "cad"});
    getAlienLanguage(v , 4);
}