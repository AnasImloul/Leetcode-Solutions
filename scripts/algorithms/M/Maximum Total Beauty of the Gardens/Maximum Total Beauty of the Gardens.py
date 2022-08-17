import bisect
class Solution:
    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        n = len(flowers)
        flowers.sort()
        pre,lack = [0],[0]
        
        # corner case in which no incomplete garden can be created. 
        if flowers[0] >= target:
            return n*full
        
        # pre-sum in an ascending order
        for i in flowers:
            pre.append(pre[-1]+i)
        
        # pre-sum in a descending order, meanwhile, count how many gardens are already full
        cnt = 0
        for i in flowers[::-1]:
            if i >= target:
                cnt+=1
            lack.append(lack[-1]+max(target-i,0))
        
        # conditional checker: whether all first k elements can >= flower after adding f to them
        def fill(flower,f,k):
            i = bisect.bisect_left(flowers,flower,lo=0,hi=k)
            return pre[i] + f >= i*flower
            
        res = 0
        # start from the min number of full gardens
        for k in range(cnt,n):
            if lack[k] < newFlowers:
                left, right = flowers[0], target+1
                while left < right:
                    mid = (left+right)//2
                    if not fill(mid,newFlowers-lack[k],n-k):
                        right = mid
                    else:
                        left = mid + 1
                left -= 1
                
                if left >= target:
                    # the n-k gardens must be incomplete, which can have a max value as target-1
                    
                    res = max(res,(target-1)*partial+k*full)
                else:
                    res = max(res,k*full+left*partial)
        
        # A corner case: All n gardens can be full, no incomplete gardens
        if lack[-1] <= newFlowers:
            res = max(res,n*full)
        return res
        
            
