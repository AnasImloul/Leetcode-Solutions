class Solution:
    def minSteps(self, s: str, t: str) -> int:
        sMap = dict()
        tMap = dict()
        
        for character in s:
            sMap[character] = sMap.get(character, 0) + 1
        
        for character in t:
            tMap[character] = tMap.get(character, 0) + 1
            
        count = 0
        
        for key, value in sMap.items():
            if value >= tMap.get(key, 0):
                count += (value - tMap.get(key, 0))
        
        for key, value in tMap.items():
            if value >= sMap.get(key, 0):
                count += (value - sMap.get(key, 0))
        
        return count
