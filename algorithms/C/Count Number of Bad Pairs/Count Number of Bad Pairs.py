class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        nums_len = len(nums)
        count_dict = dict()
        for i in range(nums_len):
            nums[i] -= i
            if nums[i] not in count_dict:
                count_dict[nums[i]] = 0
            count_dict[nums[i]] += 1
        
        count = 0
        for key in count_dict:
            count += math.comb(count_dict[key], 2)
        return math.comb(nums_len, 2) - count
