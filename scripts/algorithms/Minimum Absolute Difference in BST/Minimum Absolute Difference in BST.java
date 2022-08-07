class Solution {
    public int getMinimumDifference(TreeNode root) {
      Queue<Integer> queue=new PriorityQueue<>();
      Queue<TreeNode> nodesQueue=new LinkedList<>();
      int min=Integer.MAX_VALUE;
      if(root==null)
        return 0;
      nodesQueue.add(root);
      while(!nodesQueue.isEmpty())
      {
        TreeNode node=nodesQueue.poll();
        queue.add(node.val);
        if(node.left!=null)
        { 
          nodesQueue.add(node.left);
        }
        if(node.right!=null)
        { 
          nodesQueue.add(node.right);
        }
      }
      int prev=queue.poll();
      while(!queue.isEmpty())
      {
        int current=queue.poll();
        int absValue=Math.abs(current-prev);
        prev=current;
        min=Math.min(min,absValue);
        
      } 
      return min;
    }
}
