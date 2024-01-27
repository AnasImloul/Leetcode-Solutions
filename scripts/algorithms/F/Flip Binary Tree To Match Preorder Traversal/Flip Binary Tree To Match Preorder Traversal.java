// Runtime: 0 ms (Top 100.0%) | Memory: 42.10 MB (Top 56.52%)

class Solution {
    int vix = 0;
    List<Integer> ans = new ArrayList<>();
    private void dfs(TreeNode node, int[] V) {
        if (node == null || (ans.size() != 0 && ans.get(0) == -1)) return;
        if (node.val != V[vix++])
            ans = new ArrayList<Integer>(Arrays.asList(-1));
        else if (node.left != null && node.left.val != V[vix]) {
            ans.add(node.val);
            dfs(node.right, V);
            dfs(node.left, V);
        } else {
            dfs(node.left, V);
            dfs(node.right, V);
        }
    }
    public List<Integer> flipMatchVoyage(TreeNode root, int[] V) {
        dfs(root, V);
        return ans;
    }
}
