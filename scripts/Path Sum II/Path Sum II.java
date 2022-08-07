class Solution 
{
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) 
    {
        List<List<Integer>> ans = new ArrayList<>();
        pathSum(root, targetSum, new ArrayList<>(), ans);
        return ans;
    }
    
    public void pathSum(TreeNode root, int targetSum, List<Integer> path, List<List<Integer>> ans)
    {
        if(root == null)
            return;
        path.add(root.val);
        if(root.left == null && root.right == null && targetSum == root.val)//leaf node that completes path
        {
            ans.add(new ArrayList(path));// we use new ArrayList because if we don't the originaly List is added which is mutable, if we add a copy that's not mutable.
        }
        else
        {
            pathSum(root.left, targetSum-root.val, path, ans);
            pathSum(root.right, targetSum-root.val, path, ans);
        }
        path.remove(path.size()-1); //removal of redundant nodes
    }
}
