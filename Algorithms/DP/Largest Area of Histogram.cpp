#include <iostream>
using namespace std;

// largest Rectangle histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n , 0) , rightSmaller(n , 0);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = st.top() + 1;
            st.push(i);
        }

        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = st.top() - 1;
            st.push(i);
        }
        int area = 0;
        for(int i=0;i<n;i++)
            area = max( area , (rightSmaller[i] - leftSmaller[i] + 1) * heights[i]);
        return area;
    }
};


int main()
{
    
    return 0;
}