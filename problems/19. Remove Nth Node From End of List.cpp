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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        int fastAheadCount = 0;

        while(fast->next != nullptr)
        {
            if(fastAheadCount >= n)
                slow = slow->next;
            else
                ++fastAheadCount;
            fast = fast->next;
        }
        
        if(fastAheadCount == n)
        {
            slow->next = slow->next->next;
            return head;
        }
        if(fastAheadCount + 1 == n)
        {
            head = slow->next;
            return head;
        }
        if(n > fastAheadCount + 1)
        {
            return head;
        }
        return head;
    }
}; 