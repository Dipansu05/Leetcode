# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        temp = []
        for lst in lists:
            while lst:
                temp.append(lst.val)
                lst=lst.next

        temp.sort()

        ans = ListNode(0)
        curr = ans

        for x in temp:
            curr.next= ListNode(x)
            curr=curr.next

        return ans.next
        