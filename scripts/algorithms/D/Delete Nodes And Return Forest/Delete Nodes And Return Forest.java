// Runtime: 28 ms (Top 5.29%) | Memory: 51.1 MB (Top 5.85%)
class Solution {

    HashMap<Integer, List<TreeNode>> parent_val_child_nodes_map;
    HashMap<Integer, TreeNode> child_val_parent_node_map;

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {

        // initialize map
        parent_val_child_nodes_map = new HashMap<> ();
        child_val_parent_node_map = new HashMap<> ();

        // fill map
        dfsFillMap(root);

        // traverse to_delete to find those that do not have parent after deleting it
        List<TreeNode> res = new ArrayList<> ();

        // actually deleting nodes
        for (int delete_val : to_delete) {

            // if the node has parent
            if (child_val_parent_node_map.containsKey(delete_val)) {
                TreeNode parent_node = child_val_parent_node_map.get(delete_val);
                if (parent_node.left != null && parent_node.left.val == delete_val) {
                    parent_node.left = null;
                }

                if (parent_node.right != null && parent_node.right.val == delete_val) {
                    parent_node.right = null;
                }
            }
        }

        // add root to the list first because root has no parent
        // only if root.val is not in to_delete
        if (!Arrays.stream(to_delete).anyMatch(j -> j == root.val)) {
            res.add(root);
        }

        // add other nodes that do not have parent
        for (int delete_val : to_delete) {
            if (parent_val_child_nodes_map.containsKey(delete_val)) {
                for (int i = 0; i < parent_val_child_nodes_map.get(delete_val).size(); i++) {

                    // make sure the add node is not in to_delete
                    int child_node_val = parent_val_child_nodes_map.get(delete_val).get(i).val;
                    if (!Arrays.stream(to_delete).anyMatch(j -> j == child_node_val)) {
                        res.add(parent_val_child_nodes_map.get(delete_val).get(i));
                    }
                }
            }
        }

        return res;
    }

    public void dfsFillMap(TreeNode root) {

        if (root == null) {
            return;
        }

        if (root.left != null) {
            parent_val_child_nodes_map.putIfAbsent(root.val, new ArrayList<> ());
            parent_val_child_nodes_map.get(root.val).add(root.left);

            child_val_parent_node_map.putIfAbsent(root.left.val, root);
            dfsFillMap(root.left);
        }

        if (root.right != null) {
            parent_val_child_nodes_map.putIfAbsent(root.val, new ArrayList<> ());
            parent_val_child_nodes_map.get(root.val).add(root.right);

            child_val_parent_node_map.putIfAbsent(root.right.val, root);
            dfsFillMap(root.right);
        }

        return;
    }
}