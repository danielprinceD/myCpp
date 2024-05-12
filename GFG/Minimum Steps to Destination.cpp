#include <iostream>

class Solution {
  public:
    
    int minSteps(int d) {
        d = abs(d);
        int step = 0 , sum = 0;
        while(sum < d || abs(sum-d)%2!=0 )
        {
            step++;
            sum+=step;
        }
        return step;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
