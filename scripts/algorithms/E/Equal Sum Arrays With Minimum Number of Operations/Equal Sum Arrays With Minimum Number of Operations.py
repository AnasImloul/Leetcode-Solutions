class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        
		# step1. determine the larger array and the smaller array, and get the difference on sum
        sum1 = sum(nums1)
        sum2 = sum(nums2)
        
        if sum1==sum2:
            return 0
        elif sum1>sum2:
            larger_sum_nums = nums1
            smaller_sum_nums = nums2
        else:
            larger_sum_nums = nums2
            smaller_sum_nums = nums1
		
        sum_diff = abs(sum1-sum2)
            
        # step2. calculate the max "gain" at each position (how much difference we can reduce if operating on that position)    
        gains_in_larger_array = [num-1 for num in larger_sum_nums]
        gains_in_smaller_array = [6-num for num in smaller_sum_nums]
        
		# step3. sort the "gain" and check the least number of steps to reduce the difference to 0
        gains = gains_in_larger_array + gains_in_smaller_array
        gains.sort(reverse = True)
        
        count = 0
        target_diff = sum_diff
        
        for i in range(len(gains)):
            target_diff -= gains[i]
            count += 1
            
            if target_diff <= 0:
                return count
		
		# return -1 if the difference still cannot be reduced to 0 even after operating on all positions
        return -1
