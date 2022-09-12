/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    bool FindVal(TreeNode* node, int val,stack<TreeNode*>& path)
    {
        if(node == nullptr)
        {
            path.pop();
            return false;
        }
        if(node->val == val)
        {
            //已经找到了p，返回true
            return true;
        }
        
        if(node->val > val)//大了，往左找
        {
            path.push(node->left);
            if(FindVal(node->left,val,path))
                return true;
        }
        else
        {
            path.push(node->right);
            if(FindVal(node->right,val,path))
                return true;
        }
        path.pop();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        stack<TreeNode*> path_q;
        path_q.push(root);
        
        stack<TreeNode*> path_p;
        path_p.push(root);
        
        FindVal(root,q->val,path_q);
        FindVal(root,p->val,path_p);
    
        int path_p_size = path_p.size();
        int path_q_size = path_q.size();
        
        while(path_p.size() != path_q.size())
        {
            if(path_p.size() > path_q.size())
                path_p.pop();
            else
                path_q.pop();
        }

        while(!path_p.empty())
        {
            if(path_p.top() == path_q.top())
                return path_p.top();
            
            path_p.pop();
            path_q.pop();

        }
        
        
        return nullptr;   
    }
};