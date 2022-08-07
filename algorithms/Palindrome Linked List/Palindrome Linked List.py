class Solution:
    def isPalindrome(self, head: "Optional[ListNode]") -> bool:
        if head.next == None: return True #if only 1 element, it's always a palindrome
        forward = head
        first_half = []
        fast = head

        while (fast != None and fast.next != None):
            first_half.append(forward.val)
            forward = forward.next
            fast = fast.next.next

        # forward should now be through half the list
        if fast != None : forward = forward.next  # if length isn't even, skip the middle number
        
        reverse = len(first_half)-1
        while forward != None:
            if forward.val != first_half[reverse]: return False
            forward = forward.next
            reverse -= 1

        return True
