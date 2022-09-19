// Runtime: 2 ms (Top 39.54%) | Memory: 43.4 MB (Top 69.45%)
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null)
            return result;
        List<Integer> rootList = new ArrayList<>();
        rootList.add(root.val);
        result.add(rootList);
        levelOrder(root,1,result);
        return result;

    }

    private void levelOrder(TreeNode root, int level, List<List<Integer>> result) {
        if(root == null)
            return;
        List<Integer> children = exploreChildren(root);
        if(!children.isEmpty()){
            if(level < result.size())
                result.get(level).addAll(children);
            else
                result.add(children);
        }
        levelOrder(root.left, level + 1, result);
        levelOrder(root.right, level + 1,result);
    }

    private List<Integer> exploreChildren(TreeNode root) {
        List<Integer> children = new ArrayList<>();
        if(root.left != null)
            children.add(root.left.val);
        if(root.right != null)
            children.add(root.right.val);
        return children;
    }
}
