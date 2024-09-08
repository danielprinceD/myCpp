#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int fact = 1;
        vector<int> num;
        for(int i=1;i<n;i++)
        {
            num.push_back(i);
            fact = fact * i;
        }
        num.push_back(n);
        string ans = "";

        while(true)
        {
            ans += to_string(num[k/fact]);
            num.erase(num.begin() + k/fact);
            if(num.size() == 0)break;
            k = k % fact;
            fact = fact / num.size();
        }
        return ans;
    }
};

int main()
{
    
}