// Runtime: 172 ms (Top 12.84%) | Memory: 123.7 MB (Top 41.81%)
class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        int n=nums.length;
        int[] dp=new int[n];
        int res=nums[0];
        Queue<Integer> queue=new PriorityQueue<>((a,b)->dp[b]-dp[a]); //Declaring Max heap

        Arrays.fill(dp,Integer.MIN_VALUE);
        dp[0]=nums[0];
        queue.offer(0);

        for(int j=1;j<n;j++){
            int i=Math.max(j-k,0); // get the furthest index possible
            while(!queue.isEmpty() && queue.peek()<i) queue.poll(); // find the global max in the specified range for that particular j index
            int idx=queue.peek();
            dp[j]=Math.max(dp[idx]+nums[j],nums[j]);
            res=Math.max(res,dp[j]);
            queue.offer(j);
        }
        return res;
    }
}