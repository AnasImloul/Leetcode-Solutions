"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':    
        node = head
        while node:
            if node.child: # If there is a child travel to last node of the child
                child = node.child
                while child.next:
                    child = child.next
                child.next = node.next # Update the next of child to the the next of the current node
                if node.next: # update the prev of the next node to chile to make it valid doubly linked list
                    node.next.prev = child
                node.next = node.child # Update the child to become the next of the current
                node.next.prev = node # update the prev of the next node to chile to make it valid doubly linked list
                node.child = None # Make the child of the current node None to fulfill the requirements
            node = node.next
        return head

# time and space complexity
# time: O(n)
# space: O(1)
