class Solution {
    public List<Integer> preorder(Node root) {
        if (root == null) return new ArrayList<Integer>();
        
        Stack<Node> stk = new Stack<Node>();
        ArrayList<Integer> arr = new ArrayList<Integer>();
        stk.push(root);
        Node ref;
        while(!stk.empty()) {
            ref = stk.pop();
            // System.out.println(ref.val);
            arr.add(ref.val);
            for(int i=ref.children.size() - 1;i>=0;i--) {
                stk.push(ref.children.get(i));
            }
        }
        return arr;
    }
}
