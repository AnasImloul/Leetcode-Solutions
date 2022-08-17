class Solution(object):
    def numberOfBeams(self, bank):
        ans, pre = 0, 0
        for s in bank:
            n = s.count('1')
            if n == 0: continue
            ans += pre * n
            pre = n
        return ans
