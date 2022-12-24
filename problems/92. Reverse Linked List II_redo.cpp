class Solution {
public:

    ListNode* prev = nullptr;
    ListNode* farNext= nullptr;
    ListNode* reverseK(ListNode* head, int k)
    {
      
        if(k == 1)
            farNext = head->next;

        auto* next = head->next;
        head->next = prev;
        prev = head;
        
        if(k > 1)
            return reverseK(next , k - 1);


        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {    
        if(left > 1)
        {
            auto* res = reverseBetween(head->next, left - 1, right - 1);;
            head->next = res;
            return head;
        }
            
        auto* res = reverseK(head, right);
        head->next = farNext;
        
        return res;
    }
};