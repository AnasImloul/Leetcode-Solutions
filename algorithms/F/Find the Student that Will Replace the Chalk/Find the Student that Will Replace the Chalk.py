class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        x = sum(chalk)
        if x<k:
            k = k%x
        if x == k:
            return 0
        i = 0
        n = len(chalk)
        while True:
            if chalk[i]<=k:
                k -= chalk[i]
            else:
                break
            i +=1
               
        return i
