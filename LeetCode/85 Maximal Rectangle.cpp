#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size() , maxA = 0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || arr[st.top()] >= arr[i]))
            {
                int height = arr[st.top()];
                st.pop();
                int width;
                if(st.empty())width = i;
                else
                    width = i - st.top()  - 1;
                maxA = max(maxA , height * width);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxim = 0;
        int n = matrix[0].size();
        vector<int> height(n , 0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '1')height[j]++;
                else height[j] = 0;
            }
            maxim = max(maxim , maxArea(height));
        }
        return maxim;
    }
};

int main()
{
    
}
 