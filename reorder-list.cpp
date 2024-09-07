# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        # reverse last half, locate half using fast slow pointer
        # 1 2 3 4 5
        # 1 2 3 5 4
        # merge halves starting with left[0] right[0]
        # at the end add left if left exit()

        fast = slow = head

        # get mid
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        # reverse right half

        second = slow.next
        prev = slow.next = None
        while second:
            tmp = second.next
            second.next = prev
            prev = second
            second = tmp


        # merge
        first, second = head, prev
        while second:
            tmp1, tmp2 = first.next, second.next
            first.next = second
            second.next = tmp1
            first, second = tmp1, tmp2

        return head
