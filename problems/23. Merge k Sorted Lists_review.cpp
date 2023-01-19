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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](auto* a, auto*b){
            return a->val > b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>, decltype(compare)> q(compare);
        ListNode* dummyHead = new ListNode(-1);
        auto* cur = dummyHead;

        queue<ListNode*> que;
        for(auto& node : lists)
            que.push(node);     
        while(!que.empty())
        {
            if(que.front())
            {
                q.push(que.front());
                if(que.front()->next)
                    que.push(que.front()->next);
            }
            que.pop();
        }
        while(!q.empty())
        {
            cur->next = q.top();
            cur = q.top();
            q.pop();
        }      
        cur->next = nullptr;  
        return dummyHead->next;
    }
};