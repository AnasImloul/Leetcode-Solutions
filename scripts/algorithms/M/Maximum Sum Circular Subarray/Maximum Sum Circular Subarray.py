# Runtime: 729 ms (Top 66.43%) | Memory: 18.9 MB (Top 76.46%)
class Solution:

    def kadanes(self,nums):

        #kadanes algo

        max_till_now = nums[0]
        curr_max = nums[0]

        for i in range(1,len(nums)):
            curr_max = max(curr_max+nums[i],nums[i])
            max_till_now = max(max_till_now,curr_max)

        return max_till_now

    def maxSubarraySumCircular(self, nums: List[int]) -> int:

        #there will be 2 case
        #case 1 : our max subarray is not wrapping i.e not circular
        #case 2: our max subarray is wrapping i.e circular

        # case 1 is easy to find
        # to find case 2 what we can do is if we multiply each nums element by -1 and
        # on that find kadanes then we will get sum of elements which is not part of maxsubarray in case2 (not part because we negate)
        # now subtract this newmax in case 2 from total nums sum, we get wrapping sum
        # max of case1 and case is our ans

        total = sum(nums)

        nonwrappingsum = self.kadanes(nums)

        # edge case when all elements are -ve then return max negative
        if nonwrappingsum<0:
            return nonwrappingsum

        #negate
        for i in range(len(nums)):
            nums[i]*=-1

        wrappingsum = total-(-self.kadanes(nums)) #-ve because originally it was negated

        return max(nonwrappingsum,wrappingsum)
