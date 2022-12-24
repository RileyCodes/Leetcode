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

    ListNode* left = nullptr;

    bool traverse(ListNode* node)
    {
        if(node == nullptr)
            return true;
        auto res = traverse(node->next);
        
        res = res && node->val == left->val;
        left = left->next;
        return res;
    }

    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }
};