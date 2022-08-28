// Runtime: 4 ms (Top 7.89%) | Memory: 54.3 MB (Top 5.35%)
class Solution {
    private class Pair{
        TreeNode node;
        int sum;
        Pair(TreeNode node, int sum){
            this.node = node;
            this.sum = sum;
        }
    }
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        return solve(root, 0, limit).node;
    }
    private Pair solve(TreeNode root, int sum, int limit){
        if(root==null) return new Pair(null, Integer.MIN_VALUE);

        Pair left = solve(root.left, sum+root.val, limit);
        Pair right = solve(root.right, sum+root.val, limit);

        root.left = left.node;
        root.right = right.node;

        int max = Integer.MIN_VALUE;
        if(left.sum!=Integer.MIN_VALUE) max = left.sum;
        if(right.sum!=Integer.MIN_VALUE) max = Math.max(max, right.sum);
        if(max==Integer.MIN_VALUE) max = 0;
        if(sum+max+root.val < limit) {
            return new Pair(null, max+root.val);
        }

        return new Pair(root, max+root.val);
    }
}