// Runtime: 156 ms (Top 74.13%) | Memory: 16.70 MB (Top 42.43%)

import heapq
class Solution:
    def power(self,n):
        if n in self.dic:
            return self.dic[n]
        if n % 2:
            self.dic[n] = self.power(3 * n + 1) + 1
        else:
            self.dic[n] = self.power(n // 2) + 1
        return self.dic[n]    
    def getKth(self, lo: int, hi: int, k: int) -> int:
        self.dic = {1:0}
        for i in range(lo,hi+1):
            self.power(i)
                        
        lst = [(self.dic[i],i) for i in range(lo,hi+1)]
        heapq.heapify(lst)
        
        for i in range(k):
            ans = heapq.heappop(lst)
        
        return ans[1]     
