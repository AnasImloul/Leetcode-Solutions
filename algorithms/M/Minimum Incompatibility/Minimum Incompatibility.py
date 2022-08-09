class Solution(object):
    def minimumIncompatibility(self, nums, k):
        nums.sort(reverse = True)
        upperbound = len(nums) // k
        arr = [[] for _ in range(k)]
        self.res = float('inf')
        def assign(i):
            if i == len(nums):
                self.res = min(self.res, sum(arr[i][0]-arr[i][-1] for i in range(k)))
                return True
            flag = 0
            for j in range(k):
                if not arr[j] or (len(arr[j]) < upperbound and arr[j][-1] != nums[i]):
                    arr[j].append(nums[i])
                    if assign(i+1):
                        flag += 1
                    arr[j].pop()
                if flag >= 2: break
            return flag != 0
        if max(collections.Counter(nums).values()) > k: return -1
        assign(0)
        return self.res
