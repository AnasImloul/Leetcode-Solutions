# Runtime: 309 ms (Top 14.94%) | Memory: 18.7 MB (Top 36.81%)
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack=[]
        res=''
        for i in range(len(s)):
            if len(stack)==0:
                stack.append([s[i],1])
            elif stack[-1][0]==s[i]:
                stack[-1][1]=stack[-1][1]+1
            else:
                stack.append([s[i],1])
            if stack[-1][1]==k:
                stack.pop()
        for i in range(len(stack)):
            res+=stack[i][0]*stack[i][1]
        return res