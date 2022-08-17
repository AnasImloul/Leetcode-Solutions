class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        HashMap<Integer,TreeNode> map=new HashMap<>();
        HashSet<Integer> children=new HashSet<>();
        for(int[] info:descriptions)
        {
            int parent=info[0],child=info[1];
            boolean isLeft=info[2]==1?true:false;
            TreeNode parentNode=null;
            TreeNode childNode=null;
            if(map.containsKey(parent))
                parentNode=map.get(parent);
            else
                parentNode=new TreeNode(parent);
            if(map.containsKey(child))
                childNode=map.get(child);
            else
                childNode=new TreeNode(child);
            if(isLeft)
                parentNode.left=childNode;
            else
                parentNode.right=childNode;
            map.put(parent,parentNode);
            map.put(child,childNode);
            children.add(child);
            
        }
        TreeNode root=null;
        for(int info[]:descriptions)
        {
            if(!children.contains(info[0]))
            {
                root=map.get(info[0]);
                break;
            }
        }
        return root;
    }
    
    
}