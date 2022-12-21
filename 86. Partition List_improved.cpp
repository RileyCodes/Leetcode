class Solution {
public:
ListNode* partition(ListNode* head, ListNode*& lP, ListNode*& geP, int x, ListNode*& gePhead, ListNode*& lPhead)
{
    if(head == nullptr)
    {
        if(lP)
            lP->next = nullptr;
        if(geP)
            geP->next = nullptr;
        return lP;
    }
    ListNode*& node = head->val < x ? lP : geP;
    if(node == nullptr)
    {
        node = head;
        if(node == lP)
            lPhead = head;
        else
            gePhead = head;
    }
    else
    {
        node->next = head;
        node = head;
    }
    return partition(head->next, lP, geP, x, gePhead, lPhead);
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