class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        // Initially assign low to 1 and high to INT_MIN
        int low = 1;
        int high = Integer.MIN_VALUE;
        
        // Assign high to maximum element in nums to reduce our search space
        for(int i=0;i<nums.length;i++) {
            high = Math.max(high,nums[i]);
        }
        
        // Keep ans for updating the answer whenever we get a sum <= threshold
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(getDivisorSum(nums,mid) <= threshold) {
                // If sum <= threshold store mid to ans and try to move leftwards
                // to get a better or more smaller answer
                ans = mid;
                high = mid - 1;
            } else {
                // If sum > threshold then we will have to increase the divisor
                // to reduce the overall sum so move rightwards
                low = mid + 1;
            }
        }        
        
        return ans;
        
        
    }
    
    public int getDivisorSum(int[] nums, int divisor) {
        int sum = 0;
        
        // Calculate divisor sum iterating over the nums array
        for(int i=0;i<nums.length;i++) {
            sum += Math.ceil((double) nums[i]/divisor);
        }
        
        return sum;
    }
}
