# Runtime: 81 ms (Top 68.03%) | Memory: 13.9 MB (Top 63.45%)
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        dec = {}
        c = 0
        res=''
        for i in indices:
            dec[i] = s[c]
            c += 1
        # dec = {"4":"c","5":"o","6":"d","7":"e","0":"l","2":"e","1":"e","3":"t"}
        for x in range(len(indices)):
            res += dec[x]
            # x in range 0, 1, 2,....... len *indices or s*
        return res