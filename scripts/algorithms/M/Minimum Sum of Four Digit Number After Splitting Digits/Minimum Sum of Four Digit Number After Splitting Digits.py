class Solution:
    def minimumSum(self, num: int) -> int:
        s = list(str(num))
        s.sort()
        s1 = s[0]+s[2]
        s2 = s[1]+s[3]
        sum = int(s1)+int(s2)
            
        return sum
