class Solution {
public:

    ListNode* partition(ListNode* head, auto& lP, auto& geP, int x, ListNode*& gePhead, ListNode*& lPhead)
    {
        if(head == nullptr)
        {
            if(lP)
                lP->next = nullptr;
            if(geP)
                geP->next = nullptr;
            return lP;
        }
        auto* node = nullptr;
        if(head->val < x)
        {
            node = &lP;
            if(lPhead == nullptr)
                lPhead = head;            
        }
        else
        {
            node = &geP;
            if(gePhead == nullptr)
                gePhead = head;
        }
            
        if(!(*node))
        {
            (*node) = head;
            return partition(head->next, lP,geP, x, gePhead,lPhead);
        }
        else
        {
            (*node)->next = head;
            (*node) = head;
            return partition(head->next, lP,geP, x, gePhead,lPhead);
        }

        return nullptr;
    }

    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *lP = nullptr, *geP = nullptr, *gepHead = nullptr, *lPhead = nullptr;
        auto* lastlP = partition(head, lP,geP,x, gepHead, lPhead);
        if(lastlP)
            lastlP->next = gepHead;
        return lPhead ? lPhead : (gepHead? gepHead: head);
    }
};