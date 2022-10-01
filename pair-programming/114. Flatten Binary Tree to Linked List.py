# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    

    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """

        def preorder(node,lst):
            
            if node == None:
                `
                return
            print(node)
            lst.append(node)
            preorder(node.left,lst)
            preorder(node.right,lst)

        lst = []
        
        preorder(root,lst)
        
        for i in range(1,len(lst)):
            lst[i - 1].right = lst[i]
            lst[i - 1].left = None
            
        
        