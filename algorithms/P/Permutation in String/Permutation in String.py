class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        s1_map = {}
        s2_map = {}
        for i in range(ord('a') , ord('z') + 1):
            s1_map[chr(i)] = 0
            s2_map[chr(i)] = 0
        
        for i in s1:
            s1_map[i] += 1
            
        l = 0
        r = 0
        
        while r < len(s2):
            print(s2_map , l ,r)
            if r == 0:
                while r < len(s1):
                    s2_map[s2[r]] += 1
                    r += 1
                if s2_map == s1_map:
                    return True

            else:
                s2_map[s2[l]] -= 1
                s2_map[s2[r]] += 1
                
                if s2_map == s1_map:
                    return True
                else:
                    l += 1
                    r += 1
            
        return False      
