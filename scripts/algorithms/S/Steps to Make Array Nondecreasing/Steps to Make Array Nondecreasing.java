// Runtime: 23 ms (Top 77.7%) | Memory: 56.11 MB (Top 49.4%)

class Solution {
    public int totalSteps(int[] nums) {
        Deque<Integer> stack = new ArrayDeque<>();
        int ans = 0;
        int[] dp = new int[nums.length];
        for (int i = nums.length - 1; i >= 0; i--){
            int cur = 0;
            while(!stack.isEmpty() && nums[i] > nums[stack.peek()]){
                cur = Math.max(cur + 1, dp[stack.pop()]);
            }
            stack.push(i);
            dp[i] = cur;
            ans = Math.max(cur, ans);
        }
        return ans;
    }
}