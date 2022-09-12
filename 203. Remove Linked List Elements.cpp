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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
 
        ListNode* keep = nullptr;
        auto* cur = head;
        head = nullptr;
        while(cur)
        {
            if(cur->val != val)
            {
                if(keep == nullptr)
                {
                    keep = cur;   
                    head = keep;
                }
                else
                {
                    keep->next = cur;
                    keep = keep ->next;
                }
            }
            else
            {
                if(keep)
                    keep->next = nullptr;
            }
            cur = cur->next;
        }
        
        return head;
    }
};