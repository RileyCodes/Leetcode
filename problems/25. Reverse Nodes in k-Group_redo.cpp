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

    ListNode* prev = nullptr;

    ListNode* reverseK(ListNode* a, ListNode* b)
    {
        //reverse until node b [a,b) and returns new head
        auto* cur = a;
        ListNode* prev = nullptr;
        while(cur != b)
        {
            auto* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        //call to reverse [a,b) and connects
        ListNode* cur = head;
        for(int i = 0; i < k; ++i)
        {
            if(cur == nullptr)
                return head;
            cur = cur->next;
        }
        auto* res = reverseK(head, cur);
        head->next = reverseKGroup(cur, k);

        return res;
    }
};