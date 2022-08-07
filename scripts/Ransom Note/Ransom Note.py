from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
         
        ransomNote_count = dict(Counter(ransomNote))
        magazine_count = dict(Counter(magazine))
        
        for key , value in ransomNote_count.items():
            
            if key in magazine_count:
                if value <= magazine_count[key]:
                    continue
            else:
                return False
            
            return False
        
        return True
