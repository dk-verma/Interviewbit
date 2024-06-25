# Problem - 98. Validate Binary Search Tree

# Constraints:
# The number of nodes in the tree is in the range [1, 104].
# -231 <= Node.val <= 231 - 1

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def check(self, root: Optional[TreeNode],minValue,maxValue) -> bool:
            if not root:
                return True
            # print(f"root val {root.val}, minValue {minValue}, maxValue {maxValue}")
            return minValue<root.val<maxValue and check(self,root.left,minValue,root.val) and check(self,root.right,root.val,maxValue)

        minValue,maxValue=-math.inf,math.inf
        return check(self,root,minValue,maxValue)
