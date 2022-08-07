class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] a=new int[]{-1,-1};
        for(int i=0,j=nums.length-1;i<nums.length && j>=0;i++,j--){
            
            if(nums[i]==target && a[0]==-1){
                a[0]=i;
            }
            if(nums[j]==target && a[1]==-1){
                a[1]=j;
            }
            if(a[0]!=-1 && a[1]!=-1){
                break;
            }
        }
        return a;
    }
    
}
