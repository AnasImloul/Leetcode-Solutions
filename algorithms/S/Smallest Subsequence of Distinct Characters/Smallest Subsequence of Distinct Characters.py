class Solution:
    def smallestSubsequence(self, s: str) -> str:
         # calculate the last occurence of each characters in s
        last_occurence = {c: i for i, c in enumerate(s)}
        
        stack = []
        # check if element is in stack
        instack = set()
        for i, c in enumerate(s):
            if c not in instack:
                # check if stack already have char larger then current char
                # and if char in stack will occur later again, remove that from stack
                while stack and stack[-1] > c and last_occurence[stack[-1]] > i:
                    instack.remove(stack[-1])
                    stack.pop()
                    
                instack.add(c)   
                stack.append(c)
        
        return "".join(stack)
