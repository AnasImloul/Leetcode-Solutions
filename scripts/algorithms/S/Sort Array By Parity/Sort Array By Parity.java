// Runtime: 1 ms (Top 100.00%) | Memory: 48.1 MB (Top 66.96%)
class Solution {

    public int[] sortArrayByParity(int[] nums) {
        int i = 0;
        int j = 0;

        while(i < nums.length){
            if(nums[i] % 2 == 1){
                i++;
            }else{
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;

                i++;
                j++;
            }
        }

        return nums;
    }
}