// Runtime: 19 ms (Top 6.94%) | Memory: 43.6 MB (Top 28.49%)
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        String s = "";
        dfs(res, root, s);
        return res;
    }

    public void dfs(List<String> res, TreeNode root, String s)
    {
        if(root==null)
            return;

        if(root.left==null && root.right==null)
        {
            res.add(s+root.val);
            return;
        }

        else
        {
            dfs(res,root.left, s + root.val + "->");
            dfs(res,root.right,s + root.val + "->");
            return;
        }
    }
}