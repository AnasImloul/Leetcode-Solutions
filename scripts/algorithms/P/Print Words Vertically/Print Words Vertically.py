
class Solution:
    def getMaxLen(self, words):
        max_len = 0
        for word in words:
            max_len = max(max_len, len(word))
        return max_len
    
    def printVertically(self, s: str) -> List[str]:
        words = s.split()
        max_len = self.getMaxLen(words)
        
        res = list()
        for i in range(max_len):
            s = ""
            for word in words:
                if i < len(word):
                    s += word[i]
                else:
                    s += " "
            s = s.rstrip()
            res.append(s)
        return res
            
            
        
		
