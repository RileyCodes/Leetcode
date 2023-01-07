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
    const int FOUND_NOTHING = 0;
    const int FOUND_SOLUTION = 1;
    const int FOUND_EXISTENCE = 2;

    int recur(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *& result) {
        if (root == nullptr)
            return FOUND_NOTHING;

        // found both side
        if ((root->left == p || root->left == q) && (root->right == p || root->right == q)) {
            result = root;
            return FOUND_SOLUTION;
        }

        int defaultResponse = FOUND_NOTHING;

        // found one side - left
        if (root->left == p || root->left == q) {
            TreeNode* leftRes = nullptr, *rightRes = nullptr;
            // check existence of left subtree
            int leftCode = recur(root->left, p, q, leftRes);
            if (leftCode == FOUND_EXISTENCE) {
                result = root->left;
                return FOUND_SOLUTION;
            }
            int rightCode = recur(root->right, p, q, rightRes);
            if (rightCode == FOUND_EXISTENCE) {
                result = root;
                return FOUND_SOLUTION;
            }
            defaultResponse = FOUND_EXISTENCE;
            result = root->left;
        }

        // found one side - right
        if (root->right == p || root->right == q) {
            TreeNode* leftRes = nullptr, *rightRes = nullptr;
            // check existence of right subtree
            int rightCode = recur(root->right, p, q, rightRes);
            if (rightCode == FOUND_EXISTENCE) {
                result = root->right;
                return FOUND_SOLUTION;
            }
            int leftCode = recur(root->left, p, q, leftRes);
            if (leftCode == FOUND_EXISTENCE) {
                result = root;
                return FOUND_SOLUTION;
            }
            defaultResponse = FOUND_EXISTENCE;
            result = root->right;
        }

        // not directly on both side
        TreeNode *leftPtr = nullptr, *rightPtr = nullptr;
        int leftCode = recur(root->left, p , q, leftPtr);
        if (leftCode == FOUND_SOLUTION) {
            result = leftPtr;
            return FOUND_SOLUTION;
        }
        int rightCode = recur(root->right, p , q, rightPtr);
        if (rightCode == FOUND_SOLUTION) {
            result = rightPtr;
            return FOUND_SOLUTION;
        }
        if (leftCode == FOUND_EXISTENCE && rightCode == FOUND_EXISTENCE) {
            result = root;
            return FOUND_SOLUTION;
        }
        if (leftCode == FOUND_EXISTENCE) {
            result = leftPtr;
            return FOUND_EXISTENCE;
        }
        if (rightCode == FOUND_EXISTENCE) {
            result = rightPtr;
            return FOUND_EXISTENCE;
        }
        return defaultResponse;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == q)
            return q;
        TreeNode* ans = nullptr;
        int status = recur(root, p, q , ans);
        if (status == FOUND_SOLUTION)
            return ans;
        else if (status == FOUND_EXISTENCE && (root == p || root == q))
            return ans;
        return nullptr;
    }
};



