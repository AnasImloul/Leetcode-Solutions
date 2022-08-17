class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n=len(arr)
        stack=[]
        left,right=[-1]*n,[n]*n
        mod=10**9+7
        ans=0
        for i in range(n-1,-1,-1):
            while stack and arr[stack[-1]]>arr[i]:
                stack.pop()
            if stack:
                right[i]=stack[-1]
            stack.append(i)
        stack=[]
        for i in range(n):
            while stack and arr[stack[-1]]>=arr[i]:
                stack.pop()
            if stack:
                left[i]=stack[-1]
            stack.append(i)
            ans += (right[i]-i)*(i-left[i])*arr[i]
            ans%=mod
        return ans
                
