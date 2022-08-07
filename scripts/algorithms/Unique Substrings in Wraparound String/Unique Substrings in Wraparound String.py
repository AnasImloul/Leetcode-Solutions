def get_next(char):
    x = ord(char)-ord('a')
    x = (x+1)%26
    return chr(ord('a') + x)
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        i = 0
        n = len(p)
        map_ = collections.defaultdict(int)
        while i<n:
            start = i
            prev_val = p[i]
            while i+1<n and get_next(prev_val) == p[i+1]:
                prev_val = p[i+1]
                i+=1
            while start <= i:
                curr_val = i-start+1
                map_[p[start]] = max(map_[p[start]], curr_val)
                start += 1
            i+=1
        return sum(map_.values())

