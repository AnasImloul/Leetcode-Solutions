# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        # Intialize the result and the current node to the head
        res = node = head

        # Initialize the index of the current node to 0
        i = 0

        # Initialize the head and tail of the reversed nodes group to None
        reversedHead, reversedTail = None, None

        # Initialize the tail of the previous group to None
        previousTail = None

        # Iterate through all nodes
        while node:

            # When we reach the first node in a group
            if i % k == 0:

                # If there is a previous group, connect its tail to the current node
                # This is the case when we have less than k nodes left
                if previousTail:
                    previousTail.next = node

                # Initialize the head and tail of the reversed nodes group
                reversedHead = reversedTail = ListNode(node.val)

            # Continue to reverse subsequent nodes
            else:
                reversedHead = ListNode(node.val, reversedHead)

            # If we are able to reach the last node in a reversed nodes group
            if i % k == k - 1:

                # If there is a previous group, connect its tail to the current node
                # This is the case when we have k nodes and thus, we should reverse this group
                if previousTail:
                    previousTail.next = reversedHead

                # Set the tail of the previous group to the tail of the reversed nodes group
                previousTail = reversedTail

            # Set the head of the first reversed nodes group as the result
            if i == k - 1:
                res = reversedHead

            # Continue to the next node
            i, node = i + 1, node.next

        return res
