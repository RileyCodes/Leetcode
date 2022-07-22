/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* MergeNode(TreeNode* tree1Node, TreeNode* tree2Node)
    {
        if(tree1Node == nullptr && tree2Node == nullptr)
            return nullptr;
        else if(tree1Node == nullptr)
            return tree2Node;
        else if(tree2Node == nullptr)
            return tree1Node;
        return new TreeNode(tree1Node->val + tree2Node->val); 
    }
    
    void _visit(TreeNode* node1,TreeNode* node2,TreeNode* node3)
    {
        TreeNode* pNode1_left = !node1? nullptr : node1->left;
        TreeNode* pNode2_left = !node2? nullptr : node2->left;
        TreeNode* pNode1_right = !node1? nullptr : node1->right;
        TreeNode* pNode2_right= !node2? nullptr : node2->right;
        
        node3->left = MergeNode(pNode1_left,pNode2_left);
        node3->right = MergeNode(pNode1_right,pNode2_right);
        
        if(pNode1_left != nullptr || pNode2_left != nullptr)
        {
            _visit(pNode1_left,pNode2_left,node3->left);
        }
        
        if(pNode1_right != nullptr || pNode2_right != nullptr)    
        {
            _visit(pNode1_right,pNode2_right,node3->right);
        }
        
        return;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        auto root3 = MergeNode(root1,root2);
        if(root3 == nullptr)
            return nullptr;
        
        _visit(root1,root2,root3);
        
        return root3;
    }
};