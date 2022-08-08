class Solution {
    public int tallestBillboard(int[] rods) {
        int[] result = new int[1];
        dfs(rods, 0, 0, 0, rods.length, result);
        return result[0];
    }
    private void dfs(int[] rods, int left, int right, int level, int n, int[] result) {
        if (level == n) {
            if (left == right) {
                result[0] = Math.max(left, result[0]);
            }
            return;
        }
        
        dfs(rods, left, right, level + 1, n, result);
        dfs(rods, left + rods[level], right, level + 1, n, result);
        dfs(rods, left, right + rods[level], level + 1, n, result);
    }
}
