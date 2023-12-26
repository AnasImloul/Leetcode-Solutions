// Runtime: 38 ms (Top 66.92%) | Memory: 17.30 MB (Top 6.27%)

class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        return [(s+k*fill)[i:i+k] for i in range(0,len(s),k)]
