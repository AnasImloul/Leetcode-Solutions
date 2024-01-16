// Runtime: 7 ms (Top 99.87%) | Memory: 78.10 MB (Top 82.24%)

class Solution {
    private int maxDistance = 0;

    public int amountOfTime(TreeNode root, int start) {
        traverse(root, start);
        return maxDistance;
    }

    private int traverse(TreeNode root, int start) {
        int depth = 0;
        if (root == null) {
            return depth;
        }

        int leftDepth = traverse(root.left, start);
        int rightDepth = traverse(root.right, start);

        if (root.val == start) {
            maxDistance = Math.max(leftDepth, rightDepth);
            depth = -1;
        } else if (leftDepth >= 0 && rightDepth >= 0) {
            depth = Math.max(leftDepth, rightDepth) + 1;
        } else {
            int distance = Math.abs(leftDepth) + Math.abs(rightDepth);
            maxDistance = Math.max(maxDistance, distance);
            depth = Math.min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
}



