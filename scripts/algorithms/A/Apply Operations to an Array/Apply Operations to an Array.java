// Runtime: 0 ms (Top 100.0%) | Memory: 44.10 MB (Top 19.85%)

class Solution {
    public int[] applyOperations(int[] nums) {
        int length = nums.length;
        int [] arr = new int[length];

        for (int i = 0 , j = 0; i < length; i++)
        {
            if(nums[i] == 0) continue;
            
            if (i < length-1 && nums[i] == nums[i+1])
            {
                arr[j++] = 2 * nums[i];
                nums[++i] = 0;  // or i++;  only
            }else{
                arr[j++] = nums[i];
            }
        }
        return arr;
     }
}
