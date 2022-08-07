class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums)<2: return 0
        
        #radix sort
        #N = length of nums
        #find number of digits in largest number - O(K) where K = length of largest number
        longest = 0
        for i in nums:
            longest = max(longest,len(str(i)))
            
        #normalize so that all numbers have same number of digits by adding 0s at the start of shorter numbers - O(N*K)
        for i in range(len(nums)):
            if len(str(nums[i]))!=longest:
                nums[i] = '0'*(longest-len(str(nums[i]))) + str(nums[i])
            else:
                nums[i] = str(nums[i])
        
        #apply counting sort starting with each digit from the end of the last digits - O(K*N)
        for digit in range(longest-1,-1,-1):
            vals = [[] for k in range(10)]
            for num in nums:
                vals[int(num[digit])] += [num]
			#join list sorted by that digit position together:
            new = []
            for i in vals:
                new += i
            nums = new.copy()
        
        #find the largest difference in the now sorted nums - O(N)
        best_diff = 0
        for i in range(1,len(nums)):
            best_diff = max(best_diff,int(nums[i])-int(nums[i-1]))
        return best_diff
    
#Overall complexity is O(N*K) but K is at most 10 so O(10*N) = O(N) so linear
#Please correct me if I am wrong!
