class Solution {
    public int findTheWinner(int n, int k) {
	    // We set the first node and keep it (to be able to set it as the follower of the last node we will create)
        Node firstNode = new Node(1);
		// This is just part of our loop
        Node prevNode = firstNode;
        for(int i=2; i<=n; i++) {
            Node currentNode = new Node(i);
            currentNode.prev = prevNode;
            prevNode.next = currentNode;
            prevNode = currentNode;
        }
		// Then set the last and first nodes
        firstNode.prev = prevNode;
        prevNode.next = firstNode;
    }
}
