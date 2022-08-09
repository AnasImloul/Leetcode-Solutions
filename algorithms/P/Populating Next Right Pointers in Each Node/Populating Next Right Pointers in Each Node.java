class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        
        Queue<Node> q = new LinkedList();
        
        q.add(root);
        
        while(!q.isEmpty()) {
            int sz = q.size();
            Node prev = null; //This stores the last(right) node to be connected
            for (int i = 0; i < sz; i++) {
                Node node = q.poll();
				//Right is added before left so that right node is polled first
                if (node.right != null) q.add(node.right);
                if (node.left != null) q.add(node.left);
                node.next = prev;
                prev = node;
            }
        }
        return root;
    }
}
