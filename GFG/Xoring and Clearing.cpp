#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void printArr(int n, int arr[]) {
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }

    void setToZero(int n, int arr[]) {
        memset(arr , 0 , sizeof(int)* n);
    }

    void xor1ToN(int n, int arr[]) {
        for(int i=0;i<n;i++)
            arr[i] = arr[i] ^ i;
    }
};

int main()
{
    Solution s;
    int arr[] = {1 , 2 , 3 , 4 , 5};
    s.xor1ToN(5 , arr);
}
