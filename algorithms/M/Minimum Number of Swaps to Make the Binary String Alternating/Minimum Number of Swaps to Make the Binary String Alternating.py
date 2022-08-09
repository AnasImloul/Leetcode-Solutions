class Solution:
def minSwaps(self, st: str) -> int:
    
    def swap(st,c):
        n = len(st)
        mis = 0
        for i in range(n):
            if i%2==0 and st[i]!=c:
                mis+=1
            if i%2==1 and st[i]==c:
                mis+=1
        return mis//2
            
    dic = Counter(st)
    z = dic['0']
    o = dic['1']
    res=0
    if abs(z-o)>1:
        return -1
    elif z>o:
        res = swap(st,'0')
    elif o>z:
        res = swap(st,'1')
    else:
        res = min(swap(st,'0'),swap(st,'1'))
    
    return res
