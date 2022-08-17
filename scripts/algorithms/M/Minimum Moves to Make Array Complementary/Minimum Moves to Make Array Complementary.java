class Solution {
    public int minMoves(int[] nums, int limit) {
        int[] oneMove = new int[2 * limit + 2];
        Map<Integer, Integer> noMove = new HashMap<>();

        for (int i = 0; i < nums.length / 2; i++){
            int j = nums.length - 1 - i;
            noMove.merge(nums[i] + nums[j], 1, Integer::sum);
            oneMove[Math.min(nums[i], nums[j]) + 1]++;
            oneMove[Math.max(nums[i], nums[j]) + limit + 1]--;
        }

        int ans = nums.length, one = 0;
        for (int i = 2; i <= 2 * limit; i++){
            one += oneMove[i];
            ans = Math.min(ans, one + 2 * (nums.length / 2 - one) - noMove.getOrDefault(i, 0));
        }

        return ans;
    }
}
