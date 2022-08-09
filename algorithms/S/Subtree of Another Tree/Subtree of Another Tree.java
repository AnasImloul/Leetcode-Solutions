class Solution {
    
    private boolean isSameTree(TreeNode t1, TreeNode t2) {
        
        if (t1 == null && t2 == null) {
            return true;
        }
        
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        
        queue.add(t1);
        queue.add(t2);
        
        while (!queue.isEmpty()) {
            
            TreeNode n1 = queue.poll();
            TreeNode n2 = queue.poll();
            
            if (n1 == null && n2 == null) {
                continue;
            }
            
            if (n1 == null || n2 == null) {
                return false;
            }
            
            if (n1.val != n2.val) {
                return false;
            }
            
            queue.add(n1.left);
            queue.add(n2.left);
            
            queue.add(n1.right);
            queue.add(n2.right);
                      
        }
        
        return true;
    }
        
    
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
       
        if (root == null && subRoot == null) {
            return true;
        }
        else if (root != null && subRoot == null) {
            return true;
        }
        
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            
            if (node == null) {
                continue;
            }
            
            if (isSameTree(node, subRoot)) {
                return true;
            }
            
            queue.add(node.left);
            queue.add(node.right);
            
        }
        
        return false;
        
    }
}
