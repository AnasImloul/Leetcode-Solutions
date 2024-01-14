// Runtime: 2235 ms (Top 75.0%) | Memory: 31.30 MB (Top 28.57%)

class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        n = len(stations)
        lo, hi = 0, sum(stations)+k
        while lo < hi: 
            mid = lo + hi + 1 >> 1
            ok = True 
            kk = k 
            ss = stations.copy()
            prefix = 0 
            for i in range(n+r): 
                if i < n: prefix += ss[i]
                if i >= 2*r+1: prefix -= ss[i-2*r-1]
                if i >= r and prefix < mid: 
                    if kk < mid - prefix: 
                        ok = False
                        break 
                    kk -= mid - prefix 
                    if i < n: ss[i] += mid - prefix
                    prefix = mid
            if ok: lo = mid
            else: hi = mid - 1
        return lo
