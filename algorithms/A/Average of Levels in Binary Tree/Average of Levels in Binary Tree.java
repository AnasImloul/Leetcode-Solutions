class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> que= new LinkedList<>();
        List<Double> list= new ArrayList<>();
        if(root==null)
        {
            return list;
        }
        que.add(root);
        while(que.isEmpty()==false)
        {
            double sum=0;
           int n= que.size();
           for(int i=0;i<n;i++)
           {
               TreeNode node= que.poll();
               sum=sum+node.val;
               if(node.left!=null)
               {
                   que.add(node.left);
               }
               if(node.right!=null)
               {
                   que.add(node.right);
               }   
           }
            double avg= sum/n;
            list.add(avg);
        }
        return list;
        
    }
}