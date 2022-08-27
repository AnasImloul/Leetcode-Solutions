// Runtime: 0 ms (Top 100.00%) | Memory: 41.6 MB (Top 98.77%)
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return root;
        }
        Node head = null; //the start node of next level, the first left of next level
        Node prev = null; //the next pointer
        Node curr = root;

        while (curr != null) {
            //traverse the whole current level, left -> right, until we meet a null pointer
            while (curr != null) {
                if (curr.left != null) {
                    if (head == null) {
                        head = curr.left;
                        prev = curr.left;
                    } else {
                        prev.next = curr.left;
                        prev = prev.next;
                    }
                }

                if (curr.right != null) {
                    if (head == null) {
                        head = curr.right;
                        prev = curr.right;
                    } else {
                        prev.next = curr.right;
                        prev = prev.next;
                    }
                }
                curr = curr.next;
            }

            curr = head;
            prev = null;
            head = null;
        }
        return root;
    }
}