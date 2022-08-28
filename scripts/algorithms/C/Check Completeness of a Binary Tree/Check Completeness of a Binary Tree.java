// Runtime: 2 ms (Top 49.17%) | Memory: 42.4 MB (Top 73.50%)
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        boolean end = false;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();
            if(currentNode == null) {
                end = true;
            } else {
                if(end) {
                    return false;
                }
                queue.offer(currentNode.left);
                queue.offer(currentNode.right);
            }
        }
        return true;
    }
}