/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    
    private string ans;
    private bool preorder(TreeNode node,bool root)
    {
        if(node == null)
            return false;
        if(!root)
            ans += "(";
        
        ans += node.val.ToString();        
        if(node.left == null && node.right != null)
            ans += "()";
        
        preorder(node.left,false);
        preorder(node.right,false);
        if(!root)
            ans += ")";

        return true;
    }
    
    public string Tree2str(TreeNode root) {
        preorder(root,true);
        return ans;
    }
}