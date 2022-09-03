// Runtime: 1 ms (Top 77.34%) | Memory: 41.9 MB (Top 35.55%)
class Solution
{
    public boolean checkTree(TreeNode root)
    {
        return root.val == root.left.val + root.right.val; // O(1)
    }
}