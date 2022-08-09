class Solution {
    public int longestArithSeqLength(int[] nums) {
      int len=nums.length;
        HashMap<Integer,Integer>[] dp=new HashMap[len];
        int maxvalue=1;
        for(int i=0;i<len;i++){
            int curr=nums[i];
            dp[i]=new HashMap<>();
            HashMap<Integer,Integer>currmap=dp[i];
            for(int j=0;j<i;j++){
                int diff=curr-nums[j];
                 HashMap<Integer,Integer>prev=dp[j];
                int newval=prev.getOrDefault(diff,0)+1;
                currmap.put(diff,newval);
                dp[i]=currmap;
                maxvalue=Math.max(maxvalue,currmap.get(diff));
            }
        }
        return maxvalue+1;
    }
}
