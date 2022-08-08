class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        
        int[] ans = new int[nums.length];
        
        int even_pointer = 0;
        int odd_pointer = 1;
        
        for(int i = 0; i < nums.length; i++){
            
            if(nums[i] % 2 == 0){
                ans[even_pointer] = nums[i];
                even_pointer += 2;
            } else{
                ans[odd_pointer] = nums[i];
                odd_pointer += 2;
            }
            
        }
        
        return ans;
    }
}
