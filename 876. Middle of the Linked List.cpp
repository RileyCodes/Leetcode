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
    ListNode* middleNode(ListNode* head) {
        ListNode* pSlow = head;
        ListNode* pFast = head;
        while(pFast->next != nullptr)
        {
            pSlow = pSlow->next;
            if(pFast->next->next == nullptr)
                pFast = pFast->next;
            else
                pFast = pFast->next->next;
        }
        return pSlow;
    }
};