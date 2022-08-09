class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int []dp1=new int[nums.length];
        int []dp2=new int[nums.length];
        
        int sum=0;
        for(int i=0;i<nums.length;i++){
            if(i<firstLen){
                sum+=nums[i];
                dp1[i]=sum;
            }else{
                sum+=nums[i]-nums[i-firstLen];
                dp1[i]=Math.max(sum,dp1[i-1]);
            }
        }
        
        sum=0;
        for(int i=nums.length-1;i>=0;i--){
            if(i+secondLen>=nums.length){
                sum+=nums[i];
                dp2[i]=sum;
            }else{
                sum+=nums[i]-nums[i+secondLen];
                dp2[i]=Math.max(sum,dp2[i+1]);
            }
        }
        
        int max=0;
        
        for(int i=firstLen-1;i<nums.length-secondLen;i++){
            max=Math.max(max,dp1[i]+dp2[i+1]);
        }
        
        int max1=max;
        
        dp1=new int[nums.length];
        dp2=new int[nums.length];
        
        sum=0;
        for(int i=0;i<nums.length;i++){
            if(i<secondLen){
                sum+=nums[i];
                dp1[i]=sum;
            }else{
                sum+=nums[i]-nums[i-secondLen];
                dp1[i]=Math.max(sum,dp1[i-1]);
            }
        }
        
        sum=0;
        for(int i=nums.length-1;i>=0;i--){
            if(i+firstLen>=nums.length){
                sum+=nums[i];
                dp2[i]=sum;
            }else{
                sum+=nums[i]-nums[i+firstLen];
                dp2[i]=Math.max(sum,dp2[i+1]);
            }
        }
        
        max=0;
        
        for(int i=secondLen-1;i<nums.length-firstLen;i++){
            max=Math.max(max,dp1[i]+dp2[i+1]);
        }
        
        
        int max2=max;
        
        return Math.max(max1,max2);
    }
}
