// Runtime: 818 ms (Top 91.97%) | Memory: 26.40 MB (Top 28.47%)

class UnionFind: 
    
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1]*n
        
    def find(self, p): 
        if p != self.parent[p]: 
            self.parent[p] = self.find(self.parent[p])
        return self.parent[p]
    
    def union(self, p, q): 
        prt, qrt = self.find(p), self.find(q)
        if prt == qrt: return False 
        if self.rank[prt] > self.rank[qrt]: prt, qrt = qrt, prt
        self.parent[prt] = qrt
        self.rank[qrt] += self.rank[prt]
        return True 


class Solution:
    def largestComponentSize(self, A: List[int]) -> int:
        m = max(A)
        uf = UnionFind(m+1)
        seen = set(A)
        
        # modified sieve of eratosthenes 
        sieve = [1]*(m+1)
        sieve[0] = sieve[1] = 0 
        for k in range(m//2+1): 
            if sieve[k]: 
                prev = k if k in seen else 0
                for x in range(2*k, m+1, k): 
                    sieve[x] = 0
                    if x in seen: 
                        if prev: uf.union(prev, x)
                        else: prev = x
        return max(uf.rank)
