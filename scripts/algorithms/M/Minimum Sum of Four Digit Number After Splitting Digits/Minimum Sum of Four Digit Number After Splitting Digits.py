class Solution:
    def minimumSum(self, num: int) -> int:
        s=list(str(num))
        s.sort()
        return int(s[0]+s[2])+int(s[1]+s[3])