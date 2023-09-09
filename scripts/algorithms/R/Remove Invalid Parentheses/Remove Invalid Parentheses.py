# Runtime: 96 ms (Top 83.6%) | Memory: 18.67 MB (Top 9.9%)

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        ## RC ##
        ## APPROACH : BACK-TRACKING ##
        ## Similar to Leetcode 32. Longest Valid Parentheses ##
        ## LOGIC ##
        #   1. use stack to find invalid left and right braces.
        #   2. if its close brace at index i , you can remove it directly to make it valid and also you can also remove any of the close braces before that i.e in the range [0,i-1]
        #   3. similarly for open brace, left over at index i, you can remove it or any other open brace after that i.e [i+1, end]
        #   4. if left over braces are more than 1 say 2 close braces here, you need to make combinations of all 2 braces before that index and find valid parentheses.
        #   5. so, we count left and right invalid braces and do backtracking removing them
        
		## TIME COMPLEXITY : O(2^N) ## (each brace has 2 options: exits or to be removed)
		## SPACE COMPLEXITY : O(N) ##

        def isValid(s):
            stack = []
            for i in range(len(s)):
                if( s[i] == '(' ):
                    stack.append( (i,'(') )
                elif( s[i] == ')' ):
                    if(stack and stack[-1][1] == '('):
                        stack.pop()
                    else:
                        stack.append( (i,')') )         # pushing invalid close braces also
            return len(stack) == 0, stack
        
        
        def dfs( s, left, right):
            visited.add(s)
            if left == 0 and right == 0 and isValid(s)[0]:  res.append(s)
            for i, ch in enumerate(s):
                if ch != '(' and ch != ')': continue                                    # if it is any other char ignore.
                if (ch == '(' and left == 0) or (ch == ')' and right == 0): continue    # if left == 0 then removing '(' will only cause imbalance. Hence, skip.
                if s[:i] + s[i+1:] not in visited:
                    dfs( s[:i] + s[i+1:], left - (ch == '('), right - (ch == ')') )
        
        stack = isValid(s)[1]
        lc = sum([1 for val in stack if val[1] == "("]) # num of left braces
        rc = len(stack) - lc
        
        res, visited = [], set()
        dfs(s, lc, rc)
        return res