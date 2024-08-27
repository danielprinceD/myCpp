#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v({1 , 2 , 3 , 4 , 5 , 6 , 7});
    int d = 3;
    reverse(v.begin() , v.begin() + d);
    reverse(v.begin()+d , v.end());
    reverse(v.begin() , v.end());
    for(int i : v)
        cout<<i<<" ";
}