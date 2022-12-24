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

    ListNode* reverseAB(ListNode* A, ListNode* B)
    {
        /*Reverse [A,B)
        How did it work? If cur == B, while will not execute so it is [A,B)
        If we want to reverse 1->2, A should b 1 and B should be nullptr.
        This is because that 2->next is nullptr, so when we processed 2,  next will be cur->next, which is 2->next == nullptr
        Now, since B is nullptr, we will not process nullptr, but we did process 1 and 2.
        */
        
        ListNode* cur = A;
        ListNode* prev = nullptr;
        while(cur != B)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        //Since reverseAB only processes [A,B),  we will not change anything in the event where a == b.
        ListNode* a = head;
        ListNode* b = head;

        //We only reverse when we find a sequence of nodes length k
        for(int i = 0; i < k; ++i)//for loop offers power to iterate for k times. 
        {
            /*if we found a,b that's nullptr during our loop, it implies there are no enough nodes and we should return.
            This behavior raises a question as we need three nodes , not three next: "1 next 2 next 3" we only need TWO next when k is THREE
            How did it work? Note that our returning condition is b == nullptr. in the event, we have 3 nodes named 1,2,3, and k ==3
            it will be processed as "1 next 2 next 3 next nullptr", HOWEVER, since our loop only ran for THREE times, 
            despite b being set to zero, we do not have the FOURTH loop to trigger if(b == nullptr) and return.
            This behavior is consistent with the definition of reverseAB, 
            as the right end point is an open interval, our b needs to go an extra node to reverse what we want.*/
            if(b == nullptr)
                return head;
            b = b->next;
        }
        auto* newHead = reverseAB(a, b);//After the loop, our b is properly set and ready for reverse.

        //This shows that a is set by recursion , which is b, and recall that b is the next node of what's being reversed.
        //By definition, reverseKGroup always return the head of sub linked list, and since a is now b (reversed from left to right)
        //it makes sense that the rightmost node will need to connect to the leftmost(head) of next sub linkded list.
        //Note that since reverseKGroup executes after reverseAB, the head returned by reverseKGroup are always the updated, correct head.
        a->next = reverseKGroup(b, k);
    
        return newHead;
    }
};