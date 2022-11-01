// Runtime: 7 ms (Top 8.73%) | Memory: 45 MB (Top 22.93%)
class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        if (root.left == null && root.right == null) return root;
        int depth = findDepth(root);
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int count = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            count++;
            if (count == depth) {
                break;
            }
            for (int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                if (cur.left != null) q.offer(cur.left);
                if (cur.right != null) q.offer(cur.right);
            }
        }
        Set<Integer> set = new HashSet<>();
        while (!q.isEmpty()) {
            set.add(q.poll().val);
        }
        return find(root, set);
    }

    public int findDepth(TreeNode root) {
        if (root == null) return 0;
        int left = findDepth(root.left);
        int right = findDepth(root.right);
        return 1 + Math.max(left, right);
    }

    public TreeNode find(TreeNode root, Set<Integer> set) {
        if (root == null) return root;
        if (set.contains(root.val)) return root;
        TreeNode left = find(root.left, set);
        TreeNode right = find(root.right, set);
        if (left != null && right != null) return root;
        else if (left != null) return left;
        else if (right != null) return right;
        else return null;
    }
}
