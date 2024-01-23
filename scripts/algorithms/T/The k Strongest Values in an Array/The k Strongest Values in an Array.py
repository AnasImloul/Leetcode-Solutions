// Runtime: 708 ms (Top 81.36%) | Memory: 29.90 MB (Top 95.48%)

class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        mid = arr[(len(arr)-1)//2]
        ans = []
        l ,r = 0, len(arr)-1
        while(l <= r):
            if abs(arr[l] - mid) > abs(arr[r]-mid)  :
                ans.append(arr[l])
                l+=1
            else:
                ans.append(arr[r])
                r-=1
        return ans[:k]
