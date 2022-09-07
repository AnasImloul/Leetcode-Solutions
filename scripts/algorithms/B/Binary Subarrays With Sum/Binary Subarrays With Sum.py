# Runtime: 680 ms (Top 7.52%) | Memory: 17.5 MB (Top 60.81%)
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        my_dict = {0:1}
        accum, res = 0, 0
        for n in nums:
            accum += n
            diff = accum-goal
            if diff in my_dict:
                res += my_dict[diff]
            if accum in my_dict:
                my_dict[accum] +=1
            else:
                my_dict[accum] =1
        return res