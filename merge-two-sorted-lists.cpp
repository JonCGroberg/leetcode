class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        # create a new list using a dummy node 
        # at the end return dummy.next
        dummy = ListNode()
        newList = dummy

        # check list 1 and 2, the smallest node gets added to the head
        while list1 and list2:
            if list1.val < list2.val:
                newList.next = list1
                list1=list1.next
            else:
                newList.next = list2
                list2 = list2.next

            newList = newList.next

        if list1:
            newList.next = list1
        if list2:
            newList.next = list2
        
        return dummy.next
