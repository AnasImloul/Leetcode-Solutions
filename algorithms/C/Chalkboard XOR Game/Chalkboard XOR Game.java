class Solution {
    public boolean xorGame(int[] nums) {
        int x = 0;
        for(int i=0;i<nums.length;i++){
            x^=nums[i];
        }
        // if(x==0 || nums.length%2==0) // **This also works **
        //     return true;
        // return false;
        return (x==0 || nums.length%2==0);
    }
}
