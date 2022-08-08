from itertools import permutations
class Solution:
    def invalid(self, x):
        n = len(x)
        flag = False
        for i in range(n):
            if flag: break
            for j in range(i+2, n):
                if flag: break
                for k in range(i+1, j):
                    if 2*x[k] == x[i]+x[j]: flag = True; break
        return flag
        
    def beautifulArray(self, n: int) -> List[int]:
        for perm in permutations(range(1, n+1)):
            if not self.invalid(perm):
                return perm
