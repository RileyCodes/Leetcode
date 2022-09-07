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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int headACount = 0;
        int headBCount = 0;
        
        ListNode* cur = headA;
        while(cur)
        {
            ++headACount;
            cur = cur->next;
        }
        
        cur = headB;
        while(cur)
        {
            ++headBCount;
            cur = cur->next;
        }        
        
        
        int headAExtra = headACount - headBCount;
        int headBExtra = headBCount - headACount;
        
        for(int i = 0 ; i < headAExtra ;++i)
        {
            headA = headA->next;
        }
        
        for(int i = 0 ; i < headBExtra ;++i)
        {
            headB = headB->next;
        }        
        
        
        while(headA)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        
        return nullptr;
    }
};