#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next)return head;
        stack<int> q;
        ListNode* ptr = head;
        while(ptr)
        {
            while( !q.empty() && q.top() < ptr->val )
             q.pop();

            q.push(ptr->val);
            ptr = ptr->next;
        }
        
        ListNode *ans = NULL;
        while(!q.empty())
        {
            ListNode* temp = new ListNode(q.top());
            if(!ans)
                ans = temp;
            else
                {
                    temp->next = ans;
                    ans = temp;
                }
                q.pop();
        }
        return ans;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
