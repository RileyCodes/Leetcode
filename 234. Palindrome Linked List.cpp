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
    bool isPalindrome(ListNode* head) {
        //这道题要求的必须是整个是palaindrome，局部的不行
        //所以我们可以先计数
        //我们有奇数对称和偶数对称两种情况，如12 21和12 3 21
        //值得注意的是，不管是奇数还是偶数， 5 / 2 = 2.5 = 2
        //7 / 2 = 3.5 = 3
        //然而长度是7的串，123x321 只需要检查左右3个就可以了 长度是5的串，12x21，也只需要检查左右2个。
        //这和偶数的 2 / 2 = 1,  4 / 2 = 2是一回事，所以我们似乎不用额外担心奇数偶数的问题。
        
        
        //首先对链表长度计数
        
        int cnt = 0;
        auto* cur = head;
        while(cur)
        {
            ++cnt;
            cur = cur->next;
        }
        
        if(cnt <= 1)
            return true;
        
        //得到需要反转的位置
        
        bool is_even = cnt % 2 == 0;
        
        //如果是长度为5的链表，我们需要检查链表头2个和后面2个是否是镜像，后面2个是从第三个之后的节点。
        int mirrorIndex = is_even? cnt / 2 : (cnt / 2) + 1;
        
        //对于前面的链表，不管是奇数还是偶数都只需要关心前cnt/2个节点。
        int leftEndAt = cnt / 2;
        
        cur = head;
        
        ListNode* mirrorHead = nullptr;
        ListNode* prev = nullptr;
        
        for(int i = 0; cur; ++i)
        {
            if(i < mirrorIndex)//还没抵达镜像节点
            {
                cur = cur->next;
                continue;
            }
                
            //缓存next，因为我们接下来会替换cur的next
            auto* next = cur->next;

            //当前节点要从指向下一个节点改成指向上一个节点            
            cur->next = prev;
            prev = cur;
            
            //然后检查是否是最后一个节点，如果是，那么这个节点则是镜像链表的头。
            if(next == nullptr)
            {
                //到头了算法到此为止
                mirrorHead = cur;
                break;
            }
            
            cur = next;
        }
        
        //开始比较
        
        bool isSame = true;
        cur = head;
        auto* cur2 = mirrorHead;

        for(int i = 0; i < leftEndAt; ++i)
        {
            if(cur->val != cur2->val)
                isSame = false;
            cur = cur->next;
            cur2 = cur2->next;
        }
        
        return isSame;
        
        
    }
};