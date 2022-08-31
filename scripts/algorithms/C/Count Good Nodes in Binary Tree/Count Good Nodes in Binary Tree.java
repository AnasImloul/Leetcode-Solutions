// Runtime: 2 ms (Top 100.00%) | Memory: 50.3 MB (Top 97.37%)
class Solution {
    int ans = 0;
    public int goodNodes(TreeNode root) {
        if (root == null) return 0;
        dfs(root, root.val);
        return ans;
    }

    void dfs(TreeNode root, int mx) {
        if (root == null) return;

        mx = Math.max(mx, root.val);
        if(mx <= root.val) ans++;

        dfs(root.left, mx);
        dfs(root.right, mx);

    }
}