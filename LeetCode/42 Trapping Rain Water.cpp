#include <iostream>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxi = -1;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi , height[i]);
            left[i] = maxi;
        }
        maxi = -1;
        for(int i=n-1;i>=0;i--)
        {
            maxi = max(maxi , height[i]);
            right[i] = maxi;
        }
        int tot = 0;
        for(int i=0;i<n;i++)
        {
            tot += min(left[i] , right[i]) - height[i];
        }

        return tot;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
