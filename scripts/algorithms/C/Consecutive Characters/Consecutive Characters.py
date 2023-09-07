# Runtime: 30 ms (Top 32.1%) | Memory: 13.25 MB (Top 75.9%)

class Solution(object):
    def maxPower(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack=[]
        mxpow=0
        for i in s:
            if stack and stack[-1]!=i:
                mxpow=max(mxpow,len(stack))
                stack=[]
                stack.append(i)
            else:
                stack.append(i)
        mxpow=max(mxpow,len(stack))
        return mxpow