class Solution:
    def check(self,perm,n) :
        arr =[]
        for i in range(len(perm)):
            if i % 2 == 0:
                arr.append(perm[i//2])
            if i % 2 == 1:
                arr.append(perm[n//2 + (i-1)//2])
        return arr

    def reinitializePermutation(self, n: int) -> int:
        perm = []
        for i in range(n):
            perm.append(i)

        drr = perm
        c = 0
        #print(drr)
        arr =self.check(perm,n)
        if arr == drr:
            return 1
        else:
            c = c + 1

        while arr != drr:
            if arr != perm:
                perm = []
                perm = arr
                arr = self.check(perm,n)
                c = c + 1
                if arr == drr:
                    break
        return c