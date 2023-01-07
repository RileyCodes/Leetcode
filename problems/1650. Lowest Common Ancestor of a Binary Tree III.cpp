/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> path;
        while(q != nullptr)
        {
            path.insert(q);
            q = q->parent;
        }
            
        while(p != nullptr)
        {
            if(path.count(p))
                return p;
            p = p->parent;
        }
        return nullptr;
    }
};