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
    ListNode *detectCycle(ListNode *head) {
        /*Plan:
        1.Run a slow and fast pointer until they collide, both should start at same position.
        2.Reset slow pointer to head, run both pointer at speed of 1 until they collide again.
        3.return any pointer, which would be pointing to the start of cycle.*/

        ListNode *slow = head, *fast = head;

        //it is not possible to form a cycle with just one node, so its safe to require at least two nodes
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                break;
            }
        }

        //if we finished while, it may be due to fast or fast->next being nullptr, in this case, there are no cycle.
        if(fast == nullptr || fast->next == nullptr)
            return nullptr;

        while(slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};