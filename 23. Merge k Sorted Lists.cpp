class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto Compare = [](ListNode** a, ListNode** b){
            return (*a)->val > (*b)-> val;
        };

        priority_queue<ListNode**, vector<ListNode**>, decltype(Compare)> q(Compare);
        ListNode dummy(0);
        ListNode* cur = &dummy;

        for(auto&& node : lists)
        {
            if(node != nullptr)
                q.push(&node);
        }

        while(!q.empty())
        {
            cur->next = (*q.top());

            auto** nextInSameList = q.top();
            q.pop();
            (*nextInSameList) = (*nextInSameList)->next;
            if((*nextInSameList) != nullptr)
                q.push(nextInSameList);
            cur = cur->next;
        }

        return dummy.next;
    }
};