class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxstr, maxv = "", 0
        for l in s:
            if l not in maxstr:
                maxstr += l
            else:
                maxstr = maxstr[maxstr.find(l) + 1:] + l
            maxv = max(maxv, len(maxstr))
        return maxv
