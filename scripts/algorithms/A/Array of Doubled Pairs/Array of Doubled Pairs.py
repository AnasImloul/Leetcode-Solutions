# Runtime: 1769 ms (Top 5.17%) | Memory: 16.6 MB (Top 56.95%)
class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        n = len(arr)
        arr.sort()
        times = n//2
        count = {}
        for i in arr :
            if i in count:count[i] += 1
            else: count[i] = 1
        for i in count:
            if i == 0:
                tmp = count[0]//2
                times -= tmp
                if times <=0 : return True
            else:
                if i*2 in count:
                    ct1 = count[i]
                    ct2 = count[i*2]
                    while ct1 > 0 and ct2 > 0 and times > 0:
                        ct1 -= 1
                        ct2 -= 1
                        times -= 1
                    count[i] = ct1
                    count[i*2] = ct2
                    if times == 0:return True
        return False