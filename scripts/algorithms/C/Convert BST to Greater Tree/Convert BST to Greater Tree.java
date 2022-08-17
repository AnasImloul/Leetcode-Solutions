class Solution {
    public TreeNode convertBST(TreeNode root) {
    if(root!=null) {


        List<Integer> nodesValues = new ArrayList<>();
        helperNodesVales(root, nodesValues);
        traverseAndAdd(root, nodesValues);

        return root;
    }
        return null;
    }

    private void helperNodesVales(TreeNode root, List<Integer> nodesValues) {
        if (root != null) {
            nodesValues.add(root.val);
        }
        if (root.right != null) {
            helperNodesVales(root.right, nodesValues);
        }
        if (root.left != null) {
            helperNodesVales(root.left, nodesValues);
        }
        if (root == null) {
            return;
        }
    }

    private void traverseAndAdd(TreeNode root, List<Integer> nodesValues) {
        if (root != null) {
            int rootVal = root.val;
            for (int i = 0; i < nodesValues.size(); i++) {
                if (nodesValues.get(i) > rootVal)
                    root.val += nodesValues.get(i);
            }
        }
        if (root.right != null) {
            traverseAndAdd(root.right, nodesValues);
        }
        if (root.left != null) {
            traverseAndAdd(root.left, nodesValues);
        }
        if (root == null) {
            return;
        }
    }
}



