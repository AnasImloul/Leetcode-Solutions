class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle not in haystack:
            return -1
        need = len(needle)
        for i in range(len(haystack)):
            if haystack[i:i+need] == needle:
                return i
        return -1
