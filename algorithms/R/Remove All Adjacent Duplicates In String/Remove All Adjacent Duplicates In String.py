class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for x in s:
            if(len(stack)!=0 and stack[-1]==x):
                stack.pop()
            else:
                stack.append(x)
        return "".join(stack)
