class Solution {
    int sum=0;
    public int sumEvenGrandparent(TreeNode root) {
        dfs(root,null,null);
        return sum;
    }
 void dfs(TreeNode current, TreeNode parent, TreeNode grandParent) {
        if (current == null) return; // base case 
        if (grandParent != null && grandParent.val % 2 == 0) {
            sum += current.val;
        }
				//cur->cur.left ||cur.right , parent=cur,grandPrarent=parent
        dfs(current.left, current, parent)
        dfs(current.right, current, parent);
    }
    }
