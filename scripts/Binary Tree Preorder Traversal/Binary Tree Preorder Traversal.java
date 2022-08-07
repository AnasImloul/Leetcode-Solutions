class Solution {
     public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        preorderTraversal2(root, result);
        return result;
    }


    public List<Integer> preorderTraversal2(TreeNode root,List<Integer> result) {
        if(root!=null){
               result.add(root.val);
            if(root.left!=null){
                preorderTraversal2(root.left,result);
            }
            if(root.right!=null){
                preorderTraversal2(root.right,result);
            }
        }
        return result;
    }
}
