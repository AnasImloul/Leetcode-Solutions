// Runtime: 2 ms (Top 87.02%) | Memory: 54.8 MB (Top 82.69%)
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