# Runtime: 132 ms (Top 99.26%) | Memory: 19.70 MB (Top 97.71%)

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        longest_s = ''
        curr_s = ''
        for i in s:
            if i not in curr_s:
                curr_s += i
                if len(curr_s) >= len(longest_s):
                    longest_s = curr_s
            else:
                curr_s = curr_s[curr_s.index(i)+1:]+i
        
        return len(longest_s)
