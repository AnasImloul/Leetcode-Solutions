class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        freq = [0]*26 
        
        for w in B: 
            temp = [0]*26
            for c in w: temp[ord(c)-97] += 1
            for i in range(26): freq[i] = max(freq[i], temp[i])
                
        ans = []
        for w in A: 
            temp = [0]*26
            for c in w: temp[ord(c)-97] += 1
            if all(freq[i] <= temp[i] for i in range(26)): ans.append(w)
        return ans 