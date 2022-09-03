# Runtime: 81 ms (Top 55.38%) | Memory: 14.3 MB (Top 86.51%)
class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        new_str = s.replace("-", "")
        res = ""
        j = len(new_str)-1
        i = 0
        while j >= 0:
            res += new_str[j].upper()
            i += 1
            if i == k and j != 0:
                res += "-"
                i = 0
            j -= 1
        return res[::-1]