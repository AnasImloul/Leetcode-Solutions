// Runtime: 15 ms (Top 57.67%) | Memory: 71 MB (Top 82.51%)
class Solution {

    int ans = 0;
    public int maxSumBST(TreeNode root) {
        solve(root);
        return ans;
    }
    // int[] = { min, max, sum };
    private int[] solve(TreeNode root) {
        if(root == null)
            return new int[] { Integer.MAX_VALUE, Integer.MIN_VALUE, 0 };

        int[] left = solve(root.left);
        int[] right = solve(root.right);

        if(root.val > left[1] && root.val < right[0]) {
             int sum = left[2] + right[2] + root.val;
             ans = Math.max(ans, sum);
             return new int[] { Math.min(left[0], root.val), Math.max(root.val, right[1]), sum };
        }

        return new int[] { Integer.MIN_VALUE, Integer.MAX_VALUE, 0 };
    }

}