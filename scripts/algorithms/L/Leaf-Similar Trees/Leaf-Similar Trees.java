// Runtime: 1 ms (Top 65.37%) | Memory: 42.6 MB (Top 13.06%)
class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> list1 = new ArrayList<>();
        checkLeaf(root1, list1);
        List<Integer> list2 = new ArrayList<>();
        checkLeaf(root2, list2);

        if(list1.size() != list2.size()) return false;

        int i = 0;
        while(i < list1.size()){
            if(list1.get(i) != list2.get(i)){
                return false;
            }
            i++;
        }
        return true;
    }

    private void checkLeaf(TreeNode node, List<Integer> arr){
        if(node.left == null && node.right == null) arr.add(node.val);
        if(node.left != null) checkLeaf(node.left, arr);
        if(node.right != null) checkLeaf(node.right, arr);
    }
}