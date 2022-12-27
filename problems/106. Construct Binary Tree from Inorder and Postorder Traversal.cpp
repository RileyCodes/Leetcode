class Solution {
public:

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
    TreeNode* recur(vector<int>& postorder, vector<int>& inorder, int postStart, int postEnd, int inStart, int inEnd)
    {
        if(postStart > postEnd || inStart > inEnd)
            return nullptr;                        

        int rootVal = postorder[postEnd];
        int inorderRootIndex = -1;
        for(int i = inStart; i <= inEnd; ++i)
        {
            if(inorder[i] == rootVal)
            {
                inorderRootIndex = i;
                break;
            }
        }


        int leftSize = inorderRootIndex;
        int rightSize = inEnd - inorderRootIndex;        

        auto* node = new TreeNode(rootVal);

        int rlBound = postEnd - rightSize;
        node->right = recur(postorder, inorder, 
        rlBound, postEnd - 1,
        inorderRootIndex + 1, inEnd);

        node->left = recur(postorder, inorder, 
        postStart, rlBound - 1, 
        inStart, inorderRootIndex - 1);

        return node;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postStart = 0;
        int postEnd = postorder.size() - 1;

        int inStart = 0;
        int inEnd = postorder.size() - 1;

        int rootVal = postorder[postEnd];
        int inorderRootIndex = -1;
        for(int i = inStart; i <= inEnd; ++i)
        {
            if(inorder[i] == rootVal)
            {
                inorderRootIndex = i;
                break;
            }
        }


        int leftSize = inorderRootIndex;
        int rightSize = inEnd - inorderRootIndex;     

        auto* node = new TreeNode(rootVal);

        int rlBound = postEnd - rightSize;
        node->right = recur(postorder, inorder, 
        rlBound, postEnd - 1,
        inorderRootIndex + 1, inEnd);

        node->left = recur(postorder, inorder, 
        postStart, rlBound - 1, 
        inStart, inorderRootIndex - 1);


        return node;        
    }
};