class Solution {
    public List<Integer> vals = new ArrayList<>();
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root==null) return vals;
        inorderTraversal(root.left);
        vals.add(root.val);
        inorderTraversal(root.right);
        return vals;
    }
}
