class Solution:
    def minMaxGame(self, a: List[int]) -> int:
        
        def solve(n):
            if n==1:
                return
            for i in range(n//2):
                if i%2:
                    a[i] = max (a[2*i], a[2*i+1])
                else:
                    a[i] = min (a[2*i], a[2*i+1])
            solve(n//2)
            return
        solve(len(a))
        return a[0]
