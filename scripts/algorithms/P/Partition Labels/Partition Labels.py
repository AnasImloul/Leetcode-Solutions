class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        d = defaultdict(list)
        for i, char in enumerate(s):
            d[char].append(i)
        nums = []
        
        for v in d.values():
            nums.append([v[0], v[-1]])

        start = nums[0][0]
        maxIndex = nums[0][1]
        ans = []
        for i in range(1, len(nums)):
            if nums[i][0] <= maxIndex:
                maxIndex = max(maxIndex, nums[i][1])
            else:
                ans.append(maxIndex - start + 1)
                start = nums[i][0]
                maxIndex = nums[i][1]
        ans.append(maxIndex - start + 1)
        # print(ans)
        return ans
