// Runtime: 42 ms (Top 99.59%) | Memory: 17.20 MB (Top 48.85%)

class Solution:
    def decompressRLElist(self, N: List[int]) -> List[int]:
        L, A = len(N), []
        for i in range(0,L,2):
            A.extend(N[i]*[N[i+1]])
        return A
		

