class Solution {
    public int countHillValley(int[] nums) {
        int result = 0;
    
		// Get head start. Find first index for which nums[index] != nums[index-1]
		int start = 1;
		while(start < nums.length && nums[start] == nums[start-1])
			start++;

		int prev = start-1; //index of prev different value num
		for(int i=start; i<nums.length-1; i++) {
			if(nums[i] == nums[i+1]) //If numbers are same, simply ignore them
				continue;
			else {
				if(nums[i] > nums[prev] && nums[i] > nums[i+1]) //compare current num with prev number and next number
					result++;
				if(nums[i] < nums[prev] && nums[i] < nums[i+1])
					result++;
				prev = i;   // Now your current number will become prev number.
			}
		}

		return result;
	}
}