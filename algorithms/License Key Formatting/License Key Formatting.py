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
