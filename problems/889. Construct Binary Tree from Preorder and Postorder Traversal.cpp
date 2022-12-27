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

    TreeNode* recur(vector<int>& postorder, vector<int>& preorder, int preStart, int preEnd, int postStart, int postEnd)
    {        
        if(postStart > postEnd || preStart > preEnd)
            return nullptr;               

        int rootVal = preorder[preStart];
        auto* node = new TreeNode(rootVal);
        if(preStart - preEnd  == 0)
            return node;
        
        for(int i = 0; i < postorder.size(); ++i)
            postIndex[postorder[i]] = i;
        
        int leftSize = postIndex[preorder[preStart + 1]] + 1 - postStart;
        int rightSize = (postEnd - postStart - leftSize);

        node->left = recur(postorder, preorder, 
        preStart + 1, preStart + leftSize, 
        postStart, postStart + leftSize - 1);

        int rlBound = postEnd - rightSize;
        node->right = recur(postorder, preorder, 
        preStart + leftSize + 1, preEnd,
        postStart + leftSize , postEnd - 1);

        return node;
    }

    unordered_map<int,int> postIndex;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int postStart = 0;
        int postEnd = postorder.size() - 1;

        int preStart = 0;
        int preEnd = preorder.size() - 1;

        int rootVal = preorder[preStart];
        auto* node = new TreeNode(rootVal);
        if(preStart - preEnd  == 0)
            return node;
        
        for(int i = 0; i < postorder.size(); ++i)
            postIndex[postorder[i]] = i;
        
        int leftSize = postIndex[preorder[preStart + 1]] + 1 - postStart;
        int rightSize = (postEnd - postStart - leftSize);

        node->left = recur(postorder, preorder, 
        preStart + 1, preStart + leftSize, 
        postStart, postStart + leftSize - 1);

        int rlBound = postEnd - rightSize;
        node->right = recur(postorder, preorder, 
        preStart + leftSize + 1, preEnd,
        postStart + leftSize , postEnd - 1);


        return node;
    }
};