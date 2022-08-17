class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        # Top down with memo
        # Time: O(N2)
        dp = {}
        def wiggle(prevIndex, curIndex, sign):
            if curIndex >= len(nums):
                return 0
            
            if (prevIndex, curIndex, sign) in dp:
                return dp[prevIndex, curIndex, sign]
            
            diff = nums[prevIndex] - nums[curIndex]
            cur_sign = (diff > 0)
            include = exclude = 0
            
            # if sign is different, we have two option, either take that element or ignore it
            if diff != 0 and (cur_sign is not sign):
                include = 1 + wiggle(curIndex, curIndex+1, cur_sign)
                exclude = wiggle(prevIndex, curIndex+1, sign)
            # since sign is same, here we have only one option, to exclude th curIndex
            else:
                # we can merge both exclude together to reduce lines, but keeping it separate for readability
                exclude = wiggle(prevIndex, curIndex+1, sign)
            
            dp[prevIndex, curIndex, sign] = max(include, exclude)
            return dp[prevIndex, curIndex, sign]
              
        return wiggle(0, 1, None) + 1
        
        #--------------------------------------------------------------------------#
        
        # Greedy Time: O(N)
        # Count all the changes of direction (peaks and vallyes)
        count = 1
        sign = 0
        for i in range(1, len(nums)):
            if nums[i-1] < nums[i] and sign != 1:
                sign = 1
                count += 1
            elif nums[i-1] > nums[i] and sign != -1:
                sign = -1
                count +=1
        return count
