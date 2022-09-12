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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        
        int lastVal = head->val;
        
        auto* keep = head;
        auto* cur = head->next;
        while(cur)
        {
            if(cur->val == lastVal)
            {
                keep->next = nullptr;
            }
            else
            {
                keep->next = cur;
                keep = keep->next;
                lastVal = cur->val;
            }
            
            cur = cur->next;
        }
        return head;
    }
};