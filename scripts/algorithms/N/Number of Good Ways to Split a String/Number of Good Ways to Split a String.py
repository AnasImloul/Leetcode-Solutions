class Solution:
    def numSplits(self, s: str) -> int:
        one = set()
        two = set()
        dic = {}
        
        for i in s:
            dic[i] = dic.get(i, 0) + 1
            two.add(i)
        tot = 0
        
        for i in s:
            one.add(i)
            dic[i] -= 1
            if dic[i] == 0:
                two.remove(i)
            
            if len(one) == len(two):
                tot += 1
        return tot
