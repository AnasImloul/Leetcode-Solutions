class Solution {
    public List<List<Integer>> result= new ArrayList();
    public List<List<Integer>> levelOrder(Node root) {
       if(root==null) return result;
        helper(root,0);
        return result;
    }
    
    private void helper(Node node,int level){
       if(result.size()<=level){
           result.add(new ArrayList());
       }
        result.get(level).add(node.val);
        for(Node child:node.children){
            helper(child,level+1);
        }
        
    }
}
