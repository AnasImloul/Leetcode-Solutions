class Solution {
    List<Integer> result = new ArrayList<>();
    public List<Integer> postorder(Node root) {
        addNodes(root);
        return result;
    }
    
    void addNodes(Node root) {
        if (root == null) return;
        for (Node child : root.children) addNodes(child);
        result.add(root.val);
    }
}
