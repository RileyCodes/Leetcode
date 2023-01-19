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

    ListNode* reverseFirstN(ListNode* head, int n)
    {
        if(n == 1)
            return head;
        ListNode* newHead = reverseFirstN(head->next, n - 1);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int cnt = 1;
        ListNode* last = head;
        ListNode* prevLast = nullptr;
        ListNode* globalNewHead = nullptr;
        while(head)
        {
            if(cnt == k)
            {
                head = head->next;
                
                auto* localNewHead = reverseFirstN(last, k);
                if(!globalNewHead)
                    globalNewHead = localNewHead;
                last->next = head;
                if(prevLast)
                    prevLast->next = localNewHead;
                prevLast = last;

                last = head;
                cnt = 1;
                continue;
            }
            ++cnt;
            head = head->next;
        }
        return globalNewHead;
    }
};