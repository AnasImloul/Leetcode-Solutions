class Solution {
    public int maxDepth(Node root) {
        if (root == null) return 0;
        int[] max = new int[]{0};
        dfs(root,1,max);
        return max[0];
    }
    public static void dfs(Node root, int depth, int[] max) {
        if (depth>max[0]) max[0] = depth;
        if(root==null){
            return;
        }
        ++depth;
        for(Node n:root.children) dfs(n, depth, max);
    }
}
