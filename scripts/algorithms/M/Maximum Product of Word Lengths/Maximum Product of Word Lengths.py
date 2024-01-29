// Runtime: 332 ms (Top 87.93%) | Memory: 19.80 MB (Top 74.15%)

class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n=len(words)
        
        bit_masks = [0] * n
        lengths = [0] * n
        
        for i in range(n):             
            for c in words[i]:
                bit_masks[i]|=1<<(ord(c) - ord('a')) # set the character bit            
            lengths[i]=len(words[i])
                        
        max_val = 0
        for i in range(n):
            for j in range(i+1, n):
                if not (bit_masks[i] & bit_masks[j]):
                    max_val=max(max_val, lengths[i] * lengths[j])
        
        return max_val  
