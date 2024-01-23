#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int size = nums.size(), i = 0;
        while (val != nums[i])
        {
            i++;
        }
        int j = size - 1;
        while (nums[j] != val)
        {
            j--;
        }
        j += 1;
        int tot = j - i;
        while (j < size)
        {
            nums[i] = nums[j];
            i++;
            j++;
        }

        return tot;
    }
};

int main()
{
    vector<int> v = {0, 0, 1, 2, 2, 2, 3, 4};
    Solution s;
    cout << s.removeElement(v, 2);
    for (auto &num : v)
    {
        cout << " " << num;
    }
}