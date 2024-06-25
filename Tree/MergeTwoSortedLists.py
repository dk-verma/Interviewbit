# Problem - 21. Merge Two Sorted Lists

# Input: list1 = [1,2,4], list2 = [1,3,4]
# Output: [1,1,2,3,4,4]
  
# Constraints:
# The number of nodes in both lists is in the range [0, 50].
# -100 <= Node.val <= 100
# Both list1 and list2 are sorted in non-decreasing order.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = res = ListNode()
        while list1 and list2:
            if list1.val<list2.val:
                res.next = list1
                list1, res =list1.next, res.next
            else:
                res.next = list2
                list2, res =list2.next, res.next
        if list1 or list2:
            res.next = list1 if list1 else list2
        
        return head.next
