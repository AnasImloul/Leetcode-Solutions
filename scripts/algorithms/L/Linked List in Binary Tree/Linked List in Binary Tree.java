// Runtime: 2 ms (Top 72.52%) | Memory: 49.5 MB (Top 46.71%)
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        if(root == null) return false;
        if(issame(head, root)) return true;
        return isSubPath(head, root.left) || isSubPath(head, root.right);
    }
    private boolean issame(ListNode head, TreeNode root) {
        if(head == null) return true;
        if(root == null) return false;
        if(head.val != root.val) return false;
        return issame(head.next, root.left) || issame(head.next, root.right);
    }
}