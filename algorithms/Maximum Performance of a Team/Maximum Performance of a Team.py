class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        l = list(zip(efficiency,speed))
        l.sort(reverse=True)
        h = []
        res = 0
        mod = 1000000007
        mx_sum = 0
        print(l)
        for i in range(n):
            res = max(res , (mx_sum+l[i][1])*l[i][0])
            if len(h)<k-1:
                heappush(h,l[i][1])
                mx_sum+=l[i][1]
            elif k!=1:
                x=0
                if h:
                    x = heappop(h)
                heappush(h,max(x,l[i][1]))
                mx_sum = mx_sum - x + max(x,l[i][1])
        return res%mod
            
