# Runtime: 41 ms (Top 43.2%) | Memory: 16.29 MB (Top 65.6%)

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        l = len(str(low))
        h = len(str(high))
        ans = []
        for i in range(l,h+1):
            for j in range(1,11-i):
                t = str(j)
                for k in range(i-1):
                    t+=str(int(t[-1])+1)
                if int(t)<=high and int(t)>=low:
                    ans.append(int(t))
        ans.sort()
        return ans
