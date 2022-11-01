# Runtime: 68 ms (Top 17.05%) | Memory: 13.9 MB (Top 69.77%)
class Solution:
    def smallestNumber(self, num: int) -> int:
        lst=[i for i in str(num)]
        if num<0:
            return ''.join(['-'] + sorted(lst[1:],reverse=True))
        lst=sorted(lst)
        if '0' in lst:
            itr=0
            while itr<len(lst) and lst[itr]=='0':
                itr+=1
            if itr==len(lst): #All zeroes
                return ''.join(lst)
            return ''.join([lst[itr]]+lst[:itr]+lst[itr+1:])
        return ''.join(lst)