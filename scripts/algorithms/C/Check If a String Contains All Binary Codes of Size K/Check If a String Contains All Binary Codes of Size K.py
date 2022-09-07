# Runtime: 784 ms (Top 44.64%) | Memory: 51.2 MB (Top 58.20%)
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        lst=set()
        for i in range(len(s)-k+1):
            each_String_size_k = s[i:i+k]
            lst.add(each_String_size_k)
        if len(lst) == 2**k:
            return True
        else:
            return False
