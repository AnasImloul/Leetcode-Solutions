class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        # TC = O(NlogN) because sorting the array 
        # SC = O(1); no extra space needed; sorting was done in place.
        
        # sorting the array in descending order
        nums.sort(reverse = True)
        
        # maximum product can only occur for:
        # 1. positive no * positive no * positive no
        # 2. negative no * negative no * positive no
        
        # one negative and two positives and all negatives wont give max product
        # case where all numbers in the array are negative 
        # eg : [-4,-3,-2,-1] is covered in all positives 
        
        return max(nums[0]*nums[1]*nums[2],nums[-1]*nums[-2]*nums[0])
