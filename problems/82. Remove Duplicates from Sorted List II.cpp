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
    /*
    这道题要求把有重复数字的链表都删了，我们需要2个指针
    一个指针A，指向上一个已经确定非重复的数字
    还一个指针B，一直往一边走。
    比如说你有12334
    一开始指针B遇到1，然后遇到2，这时候确定了1是非重复的
    设指针A指向1
    指针B遇到2以后遇到3，确定了2是非重复的
    指针A指向2
    指针B遇到3以后遇到3，继续，遇到4，继续，遇到5，这时候确定了4是非重复的
    指针A把2指向4，然后自身指向4。
    指针B结束。
    时间复杂度是O(n)
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode newHead;
        newHead.next = nullptr;
        
        ListNode *pA = &newHead, *pB = head;
        
        ListNode* prev = &newHead;
        while(pB != nullptr)//循环到指针B走到头为止。
        {
            ListNode * next = pB->next;//因为每次发现唯一的数的时候，会把这个数后面的链接断掉（避免后面都是重复的，然后链接还是老的没变），断掉了pB->next就没地方去了，所以我们要先保存下来。
            //唯一节点的定义：上一个是dummy，或者和这个不一样且下一个没了，或者也和这个不一样
            if((prev == &newHead || prev->val != pB->val) &&
               (pB->next == nullptr || pB->next->val != pB->val))
            {
                pA->next = pB;
                pA = pB;
                pA->next = nullptr;
            }   

            prev = pB;
            pB = next;                
        }
        return newHead.next;
    }
};