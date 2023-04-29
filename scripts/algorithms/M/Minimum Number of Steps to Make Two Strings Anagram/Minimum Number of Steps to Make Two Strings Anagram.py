class Solution:
    def minSteps(self, s: str, t: str) -> int:
        for ch in s:
		    # Find and replace only one occurence of this character in t
            t = t.replace(ch, '', 1)
            
        return len(t)