class Solution {
    public void moveZeroes(int[] nums) {
       int a = 0, z = 0, temp;
        while(a < nums.length){
            if(nums[a] != 0){
                temp = nums[z];
                nums[z] = nums[a];
                nums[a] = temp; 
                z += 1;
            }
            a += 1;
        }
    }
}
