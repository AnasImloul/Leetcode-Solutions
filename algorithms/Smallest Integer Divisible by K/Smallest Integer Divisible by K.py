class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k % 2 == 0: return -1
        n = 1
        leng = 1
        mapp = {}
        while True:
            rem = n % k
            if rem == 0: return leng
            if rem in mapp : return -1
            mapp[rem] = True
            n = n*10 + 1
            leng += 1
        
