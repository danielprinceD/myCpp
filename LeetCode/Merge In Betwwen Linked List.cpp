#include <stdio.h>
using namespace std;

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        dummy->next = list1;
        ListNode* ptr1=list1 , *ptr2 , *ptr3 = list2;
        int i=1;
        while(i < a)
        {
            ptr1 = ptr1->next;
            i++;
        }
        ptr2 = list1;
        i = 0;
        while(i <= b )
        {
            ptr2 = ptr2->next;
            i++;
        }
        while(ptr3->next!=NULL)
            ptr3=ptr3->next;
        ptr1->next = list2;
        ptr3->next = ptr2;
        return dummy->next; 
    }
};

int main()
{
    
}
