// Runtime: 30 ms (Top 95.42%) | Memory: 16.60 MB (Top 60.78%)

class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        if len(A) >= len(B):
            if B in A: return 1
            elif B in A*2: return 2
            else: return -1
        prefix = max(0, B.find(A)) #prefix -- length of A1
        repeat, postfix = divmod(len(B)-prefix, len(A)) #postfix -- length of A2
        repeat += bool(prefix) + bool(postfix)
        if B in A * repeat: return repeat
        else: return -1 
