// Runtime: 675 ms (Top 89.58%) | Memory: 23.80 MB (Top 95.52%)

class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        ans = []
        if len(original) == m*n: 
            for i in range(0, len(original), n): 
                ans.append(original[i:i+n])
        return ans 
