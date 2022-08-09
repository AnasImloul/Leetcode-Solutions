# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    
    """
    1) wrote this function by accident
    2) summing in the right order
    """
    def reverse2Numbers(self, l1, l2):
        
        if l1.next is None and l2.next is None:
            return ListNode(l1.val+l2.val)
        
        if l1.next and l2.next:
            node = self.reverse2Numbers(l1.next, l2.next)
        if l1.next and l2.next is None:
            node = self.reverse2Numbers(l1.next, l2)
        if l2.next and l2.next is None:
            node = self.reverse2Numbers(l1, l2.next)
        
        if node.val > 9:
            node.val -= 10
            return ListNode(l1.val+l2.val+1, node)
        else:
            return ListNode(l1.val+l2.val, node)
    
    
    """
    THOUGHT PROCESS:
        1) since we need the remainder of the previous sum in the next recursion, we use another function to add a remainder
        2) now check all possible types of states and cater them
        3) there are 4 different states
            null, null
            null, not_null
            not_null, null
            not_null, not_null
        
        we are summing in the opposite direction, 
        The answer is not difficult, understanding the problem here is difficult
        we are summing 2 numbers in the following way
        
        99999
       +999
        -----
        899001
        
        rather than;
        
        99999
       +  999
        _____
       100998
        
    """
    
    def process_remainder(self, node, remainder):
        if node.val > 9:
                node.val -= 10
                remainder = 1
        else:
            remainder = 0
        return node, remainder
    
    def addTwoNumbersWithRemainder(self, l1, l2, remainder):
        
        if l1 is None and l2 is None:
            if remainder != 0:
                return ListNode(remainder)
            else:
                return 0
        
        if l1 and l2:
            node = ListNode(l1.val+l2.val+remainder)
            node, remainder = self.process_remainder(node, remainder)
            
            temp = self.addTwoNumbersWithRemainder(l1.next, l2.next, remainder)
            if temp != 0: node.next = temp
              
        if l1 and l2 is None:
            node = ListNode(l1.val+remainder)
            node, remainder = self.process_remainder(node, remainder)
            
            temp = self.addTwoNumbersWithRemainder(l1.next, l2, remainder)
            if temp != 0: node.next = temp
        
        if l2 and l1 is None:
            node = ListNode(l2.val+remainder)
            node, remainder = self.process_remainder(node, remainder)
            
            temp = self.addTwoNumbersWithRemainder(l1, l2.next, remainder)
            if temp != 0: node.next = temp
    
        return node
    
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        return self.addTwoNumbersWithRemainder(l1, l2, 0)
        
        
