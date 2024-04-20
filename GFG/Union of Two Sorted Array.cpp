#include <iostream>

class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        set<int> st;
        for(int i=0;i<n;i++)st.insert(arr1[i]);
        for(int i=0;i<m;i++)st.insert(arr2[i]);
        vector<int> v(st.begin() , st.end());
        return v;
    }
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}
