class Solution:
    def balancedStringSplit(self, s: str) -> int:
        r_count=l_count=t_count=0
        for i in s:
            if i=='R':
                r_count+=1
            elif i=='L':
                l_count+=1
            if r_count==l_count:
                t_count+=1
                r_count=0
                l_count=0
            continue
        return t_count
