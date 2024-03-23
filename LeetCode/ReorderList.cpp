#include <stdio.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        ListNode* middle = midNode(head);
        ListNode* newHead = middle->next;
        middle->next = nullptr;

        newHead = reverseLinkedList(newHead);

        ListNode* c1 = head;
        ListNode* c2 = newHead;
        ListNode* f1 = nullptr;
        ListNode* f2 = nullptr;

        while (c1 && c2) {
            f1 = c1->next;
            f2 = c2->next;

            c1->next = c2;
            c2->next = f1;

            c1 = f1;
            c2 = f2;
        }
    }

private:
    ListNode* midNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forw = nullptr;

        while (curr) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
};

int main()
{
    printf("Hello World");

    return 0;
}
