// Runtime: 0 ms (Top 100.00%) | Memory: 40.2 MB (Top 95.78%)
class Solution {
    public Node flatten(Node head) {
        Node curr = head ; // for traversal
        Node tail = head; // for keeping the track of previous node
        Stack<Node> stack = new Stack<>(); // for storing the reference of next node when child node encounters
        while(curr != null){
            if(curr.child != null){ // if there is a child
                Node child = curr.child; // creating a node for child
                if(curr.next != null){ // if there is list after we find child a child
                    stack.push(curr.next); // pushing the list to the stack
                    curr.next.prev = null; // pointing its previous to null
                }
                curr.next = child; // pointing the current's reference to child
                child.prev = curr; // pointing child's previous reference to current.
                curr.child = null; // pointing the current's child pointer to null
            }
            tail = curr ; // for keeping track of previous nodes
            curr= curr.next; // traversing
        }
        while(!stack.isEmpty()){ // checking if the stack has still nodes in it.
            curr = stack.pop(); // getting the last node of the list pushed into the stack
            tail.next = curr; // pointing the previos node to the last node
            curr.prev = tail; // pointing previos pointer of the last node to the previos node.
            while( curr != null){ // traversing the last node's popped out of stack
                tail = curr;
                curr = curr.next ;
            }
        }
        return head;
    }
}