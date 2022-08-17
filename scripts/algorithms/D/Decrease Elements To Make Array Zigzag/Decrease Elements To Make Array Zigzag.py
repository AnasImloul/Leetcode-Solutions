class Solution:
    def solve(self,arr,n,x):
        idx = 1
        ans = 0
        while idx < n:
            if idx == 0: idx += 1
            if idx % 2 == x:
                if arr[idx-1] >= arr[idx]:
                    ans += arr[idx-1] - arr[idx] + 1
                    arr[idx-1] = arr[idx] - 1
                    idx = idx-1
                else:
                    idx = idx+1
            else:
                if arr[idx-1] <= arr[idx]:
                    ans += arr[idx] - arr[idx - 1] + 1
                    arr[idx] = arr[idx-1] - 1
                idx += 1               
        return ans
    
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        ans1 = self.solve([x for x in nums],len(nums),0)
        ans2 = self.solve([x for x in nums],len(nums),1)
        return min(ans1,ans2)
