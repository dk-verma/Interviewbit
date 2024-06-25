# Problem - 102. Binary Tree Level Order Traversal

# Input: root = [3,9,20,null,null,15,7]
# Output: [[3],[9,20],[15,7]]
  
# Constraints:
# The number of nodes in the tree is in the range [0, 2000].
# -1000 <= Node.val <= 1000

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans,temp,que=[],[],[]
        if root: 
            que.append(root)
        count,size=0,len(que)

        while count<size:
            curr=que.pop(0)
            temp.append(curr.val)
            if curr.left:
                que.append(curr.left)
            if curr.right:
                que.append(curr.right)
            count+=1
            if count==size:
                count,size=0,len(que)
                ans.append([ ele for ele in temp])
                temp.clear()

        return ans
