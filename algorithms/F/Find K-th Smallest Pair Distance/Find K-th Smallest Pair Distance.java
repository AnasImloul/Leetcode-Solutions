class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int low = 0, high = nums[nums.length-1] - nums[0];
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(noOfDistancesLessThan(mid,nums) >= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    private int noOfDistancesLessThan(int dist,int[] nums){
        int count = 0,i = 0, j = 0;
        while(i<nums.length){
            while(j<nums.length && nums[j]-nums[i]<=dist){  // sliding window
                j++;
            }
            count += j-i-1;
            i++;
        }
        return count;
    }
}
