class Solution:
    def maxProduct(self, words: List[str]) -> int:
        def check(w1, w2):
            for i in w1:
                if i in w2: 
                    return False
            return True
        
        n = len(words)   
        Max = 0
        for i in range(n):
            for j in range(i+1, n):
                if check(words[i], words[j]):
                    Max = max(Max, len(words[i])*len(words[j]))      
        return Max
