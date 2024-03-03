#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = new ListNode(0);
        ptr->next = head;
        ListNode* first = ptr;
        ListNode* second = ptr;
        
        while(n--!=0)
            first = first->next;
        
        while(first->next!=nullptr)
        {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        return ptr->next;
    }
};

void print(ListNode* root)
{
    if(root==NULL)return;
    cout<<root->val;
    print(root->next);
}

int main()
{
    ListNode* head = new ListNode(10);
    ListNode* sec = new ListNode(20);
    ListNode* th = new ListNode(30);
    ListNode* four = new ListNode(40);
    ListNode* fiv = new ListNode(50);
    head->next = sec;
    sec->next = th;
    th->next = four;
    four->next = fiv;
    fiv->next = NULL;
    Solution s;
    ListNode* root = s.removeNthFromEnd(head , 2);
    print(root);
    return 0;
}
