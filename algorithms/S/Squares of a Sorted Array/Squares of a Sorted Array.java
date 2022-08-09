class Solution {
    public int[] sortedSquares(int[] nums) {
        int s=0;
        int e=nums.length-1;
        int p=nums.length-1;
        int[] a=new int[nums.length];
        while(s<=e){
            if(nums[s]*nums[s]>nums[e]*nums[e]){
                a[p--]=nums[s]*nums[s];
                s++;
            }
            else{
                a[p--]=nums[e]*nums[e];
                e--;
            }
        }
        return a;
    }
}
