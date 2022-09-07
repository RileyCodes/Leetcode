/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* node = head;
        
        while(node != nullptr)
        {
            if(node->next == (ListNode*)-1)
                return true;
            auto oldNode = node;
            node = node->next;
            oldNode->next = (ListNode*)-1;
        }
        return false;
    }
};