class Solution {
    public static void preorder(TreeNode node, ArrayList<Integer> al){
        if(node != null){
            al.add(node.val);
            preorder(node.left, al);
            preorder(node.right, al);
        }
        else{
            al.add(null);
        }
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        ArrayList <Integer> al1 = new ArrayList<>();
        ArrayList <Integer> al2 = new ArrayList<>();
        
        preorder(p, al1);
        preorder(q, al2);
        
        return al1.equals(al2);
    }
}