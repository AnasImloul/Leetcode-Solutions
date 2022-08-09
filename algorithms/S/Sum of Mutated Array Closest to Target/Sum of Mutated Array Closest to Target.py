class Solution:
    def findBestValue(self, arr: List[int], t: int) -> int:
        def getsum(x):
            s = 0
            for i in range(n):
                if arr[i] > x:
                    s += x*(n-i)
                    break
                else:
                    s += arr[i]
            return s
			
		arr.sort()
        n = len(arr)
        l, r = 0, max(arr)
        ans = [inf, inf]
        while l <= r:
            m = l+(r-l)//2
            if abs(getsum(m)-t) <= ans[0]:
                if abs(getsum(m)-t) == ans[0]:
                    ans[1] = min(m, ans[1])
                else:
                    ans = [abs(getsum(m)-t), m]
            if getsum(m) > t:
                r = m-1
            else:
                l = m+1
        
        return ans[1]
