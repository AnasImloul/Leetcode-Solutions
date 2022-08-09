class Solution:
    def checkValidString(self, s: str) -> bool:
        left,right,star = deque(), deque(), deque() #indexes of all unmatched left right parens and all '*'
        # O(n) where n=len(s)
        for i,c in enumerate(s):
            if c == '(': # we just append left paren's index
                left.append(i)
            elif c == ')': # we check if we can find a match of left paren
                if left and left[-1] < i:
                    left.pop()
                else:
                    right.append(i)
            else: #'*' case we just add the postion
                star.append(i)
        if not left and not right: return True
        elif not star: return False #no star to save the string, return False
        l,r = 0 ,len(star)-1
        #O(n) since star will be length less than n
        # Note: left, right,and star are always kept in ascending order! And for any i in left, j in right, i > j, or they would have been matched in the previous for loop.
        while l<=r:
            if left:
                if left[-1]< star[r]: # we keep using right most star to match with right most '('
                    left.pop()
                    r -= 1
                else: return False # even the right most '*' can not match a '(', we can not fix the string.
            if right:
                if right[0] > star[l]:
                    right.popleft()
                    l += 1
                else: return False
            if not left and not right: return True #if after some fix, all matched, we return True
