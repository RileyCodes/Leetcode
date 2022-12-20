/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool secondStage = false;    
public:

    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) 
                break;
        }
        if(fast == nullptr || fast->next == nullptr)
            return nullptr;

        slow = head;

        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }



        return slow;
    }
};
