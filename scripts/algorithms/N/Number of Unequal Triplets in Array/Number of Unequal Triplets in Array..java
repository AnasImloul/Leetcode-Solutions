// Runtime: 11 ms (Top 12.1%) | Memory: 40.60 MB (Top 20.0%)

class Solution {
    public int unequalTriplets(int[] nums) {
        int count = 0;
        int i = 0, j = 1, k = 2;
        while(i<nums.length-2)
        {
            if(nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]){
                count++;
            }
            k++;
            if(k == nums.length){
                j++;
                k = j+1;
            }
            if(j == nums.length - 1){
                i++;
                j = i + 1;
                k = j + 1;
            }
        }
        return count;
    }
}


