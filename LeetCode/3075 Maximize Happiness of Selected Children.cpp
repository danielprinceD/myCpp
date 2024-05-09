#include <iostream>

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin() , happiness.end());
        int j = happiness.size()-1;
        long long sum = 0 , it = 0;
        while(k--)
        {
            long long ans = happiness[j]-it;
            sum += (ans > 0) ? ans : 0;
            it++; j--;
        }
        return sum;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
