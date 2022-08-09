class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n=nums.length;
        
        HashMap<Integer,Integer> []dp=new HashMap[n];
        
        for(int i=0;i<n;i++){
            dp[i]=new HashMap<Integer,Integer>();
        }
        
        int ans=0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long cd=(long)nums[i]-(long)nums[j];
                
                if(cd<=Integer.MIN_VALUE || cd>=Integer.MAX_VALUE){
                    continue;
                }
                
                int endingAtj=dp[j].getOrDefault((int)cd,0);
                int endingAti=dp[i].getOrDefault((int)cd,0);
                
                ans+=endingAtj;
                
                dp[i].put((int)cd,endingAtj+endingAti+1);
            }
        }
        
        return ans;
    }
}
