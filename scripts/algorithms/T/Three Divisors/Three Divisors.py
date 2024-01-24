// Runtime: 34 ms (Top 88.51%) | Memory: 16.40 MB (Top 53.4%)

class Solution:
    def isThree(self, n: int) -> bool:
        return sum(n%i == 0 for i in range(1, n+1)) == 3
