class Solution {
    private static int mod=(int)1e9+7;
    public int rangeSum(int[] nums, int n, int left, int right) {
        
        PriorityQueue<int[]> pq=new PriorityQueue<>((n1,n2)->n1[1]-n2[1]);
        
        for(int i=0;i<n;i++) pq.add(new int[]{i,nums[i]});
        
        int ans=0;
        for(int i=1;i<=right;i++){
            int[] k=pq.remove();
            if(i>=left){
                ans=(ans+k[1])%mod;
            }
            if(k[0]+1<n){
                pq.add(new int[]{k[0]+1,k[1]+nums[k[0]+1]});
            }
        }
        return ans;
    }
}
