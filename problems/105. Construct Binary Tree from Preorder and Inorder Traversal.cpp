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
public:

    TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;            

        int rootVal = preorder[preStart];
        int inorderRootIndex = -1;
        for(int i = inStart; i <= inEnd; ++i)
        {
            if(inorder[i] == rootVal)
            {
                inorderRootIndex = i;
                break;
            }
        }

        auto* node = new TreeNode(rootVal);
        int leftSize = inorderRootIndex - inStart;
        int rightSize = inEnd - inorderRootIndex;

        node->left = leftSize > 0? recur(preorder, inorder, 
        preStart + 1, preEnd - rightSize,
        inStart, inorderRootIndex - 1) : nullptr;


        node->right = rightSize > 0? recur(preorder, inorder, 
        preEnd - rightSize + 1, preEnd, 
        inorderRootIndex + 1, inEnd) : nullptr;

        return node;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootVal = preorder[0];
        int inorderRootIndex = -1;
        for(int i = 0; i < inorder.size(); ++i)
        {
            if(inorder[i] == rootVal)
            {
                inorderRootIndex = i;
                break;
            }
        }
        auto* node = new TreeNode(rootVal);
        node->left = recur(preorder, inorder, 1, 0 + inorderRootIndex, 0, inorderRootIndex - 1);
        node->right = recur(preorder, inorder, inorderRootIndex + 1, preorder.size() - 1, inorderRootIndex + 1, preorder.size() - 1);

        return node;
    }
};