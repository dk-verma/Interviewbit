# Problem - 235. Lowest Common Ancestor of a Binary Search Tree

# Constraints:
# The number of nodes in the tree is in the range [2, 105].
# -109 <= Node.val <= 109
# All Node.val are unique.
# p != q
# p and q will exist in the BST.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root==None or p.val<=root.val<=q.val or p.val>=root.val>=q.val: #if root is null or p&q value lies in different side of root, root is the ancestor
            return root
        if p.val<root.val and q.val<root.val:  #if p&q value lies in left side of root
            return self.lowestCommonAncestor(root.left,p,q)
        else:                                  #if p&q value lies in right side of root
            return self.lowestCommonAncestor(root.right,p,q)
