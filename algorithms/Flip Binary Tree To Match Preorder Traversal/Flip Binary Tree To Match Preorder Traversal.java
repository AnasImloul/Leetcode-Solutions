class Solution {
    private int i = 0;
    
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        List<Integer> list = new ArrayList<>();
        flipMatchVoyage(root,voyage,list);
        return list;
    }
    
    private void flipMatchVoyage(TreeNode root, int[] voyage,List<Integer> list) {
        if(root == null || list.contains(-1)){
            return;
        }
        if(root.val != voyage[i++]){
            list.clear();
            list.add(-1);
            return;
        }
        if(root.left != null && root.right != null && root.left.val != voyage[i]){
            list.add(root.val);
            flipMatchVoyage(root.right,voyage,list);
            flipMatchVoyage(root.left,voyage,list);
            return;
        }
        flipMatchVoyage(root.left,voyage,list);    
        flipMatchVoyage(root.right,voyage,list);
    }
}