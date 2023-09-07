# Runtime: 1526 ms (Top 91.5%) | Memory: 54.78 MB (Top 12.2%)

class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        MOD = (10**9)+7
        binary = bin(n)[2:]
        powers = []
        result = []
        for index, val in enumerate(binary[::-1]):
            if val == "1":
                powers.append(2**index)
                
        for index in range(1, len(powers)):
            powers[index] = powers[index] * powers[index - 1]    
        
        for l,r in queries:
            if l == 0:
                result.append(powers[r]%MOD)
            else:
                result.append((powers[r]//powers[l-1])%MOD)
                
        return result
            