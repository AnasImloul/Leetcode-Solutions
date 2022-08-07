  class Solution:
    def nextPermutation(self, nums: List[int]):
        n = len(nums)
        high = n-1
        low = -1
        for i in range(n-1, 0, -1):
            if nums[i] > nums[i-1]:
                low = i-1
                break
        if low == -1:
            nums[low+1:] = reversed(nums[low+1:])
            return
        for i in range(n-1, low, -1):
            if nums[low] < nums[i]:
                nums[low], nums[i] = nums[i], nums[low]
                break
        nums[low+1:] = reversed(nums[low+1:])
        return nums

    def getPermutation(self, n: int, k: int) -> str:
        s = ["1","2","3","4","5","6","7","8","9"]
        s = s[:n]
        if k==1:
            return ''.join(s)
        dic = {1:1,2:2,3:6,4:24,5:120,6:720,7:5040,8:40320,9:362880}        
        if k==dic[n]:
            return ''.join(s)[::-1]
        x = 0
        while k>dic[n-1]:
            k -= dic[n-1]
            x += 1
        y=[]
        y.append(s[x])
        for i in range(n):
            if i==x:
                continue
            y.append(s[i])
        while k!=1:
            self.nextPermutation(y)
            k-= 1
        y = ''.join(y)
        return y
