// Runtime: 41 ms (Top 36.2%) | Memory: 61.93 MB (Top 47.8%)

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        List<Long> list=new ArrayList<>();
        Queue<TreeNode> qu=new LinkedList<>();
        qu.offer(root);
        while(!qu.isEmpty())
        {
            int p=qu.size();
            long s=0;
            for(int i=0;i<p;i++)
            {
                if(qu.peek().left!=null)
                    qu.offer(qu.peek().left);
                if(qu.peek().right!=null)
                    qu.offer(qu.peek().right);
                s+=(long)qu.poll().val;
            }
            list.add(s);
        }
        Collections.sort(list);
        return k > list.size() ? -1 : list.get(list.size()-k);
    }
}