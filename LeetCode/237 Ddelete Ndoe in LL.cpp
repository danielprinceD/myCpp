#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *ptr = node , *prev = NULL;
        while(ptr->next)
        {
            ptr->val = ptr->next->val;
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        delete ptr;

    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
