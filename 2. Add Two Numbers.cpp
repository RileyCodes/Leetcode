class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        bool carry = false;
        
        ListNode* cur = head;//我们一开始有个为0的节点，如果输入是空的，可以直接返回这个。
        while(l1 && l2)//假设2个链表里都有东西
        {
            //比如说9+9 = 18，带了一位变成8，第二个数又是9+9 = 18, l1 + l2 + carry = 9 + 9 +1 =19 还是带了一位
            //因此，carry最多只会carry一个
            int num = l1->val + l2->val + carry;
            carry = num >= 10;
            cur->val = num % 10;
            
            if(l1->next && l2->next)//如果还要循环，继续安排
            {
                cur->next = new ListNode(0);
                cur = cur->next;
            }
            else
                cur->next = nullptr;//避免野指针
            l1 = l1->next;
            l2 = l2->next;
        }
        
        //处理单链为null 另一边非null的情况
        if(l1)//这里我们直接复用l1或者l2的链表（接过去了），所以只需要处理一个
            cur->next = l1;
        else if(l2)
            cur->next = l2;
        
        //处理剩下的carry
        while(carry > 0)
        {
            if(cur->next == nullptr)//如果没单链，直接把carry作为一位放进去
            {
                cur->next = new ListNode(carry);            
                cur->next->next = nullptr;
                carry = false;
            }
            else
            {
                cur = cur->next;
                int num =  cur->val + carry;
                carry = num >= 10;
                cur->val = num % 10;
            }
        }
        return head;
    }
};