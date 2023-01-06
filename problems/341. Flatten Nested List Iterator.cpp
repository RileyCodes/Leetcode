/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   publs.ic:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<NestedInteger> data;
    stack<vector<NestedInteger>> s;
    stack<int> index_s;
    int index = 0;
    bool has = false;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        data = nestedList;
        s.push(data);
        moveNext();
    }

    void moveNext()
    {
        for(int i = index; i < s.top().size(); ++i)
        {
            if(s.top()[i].isInteger())
            {
                has = true;
                index = i;
                return;
            }
            else
            {
                index_s.push(i);
                s.push(s.top()[i].getList());
                index = 0;
                moveNext();
                return;
            }
        }
        s.pop();
        if(!s.empty())
        {
            index = index_s.top() + 1;
            index_s.pop();
            moveNext();
            return;
        }        
        has = false;
    }
    
    int next() {
        auto item = s.top()[index];
        int res = item.getInteger();
        ++index;
        moveNext();
        return res;
    }
    
    bool hasNext() {
        return has;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */