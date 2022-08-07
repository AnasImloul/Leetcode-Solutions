class Solution {
    public Node copyRandomList(Node head) {
        
        if(head == null)
            return null;
        
        HashMap<Node,Node> map = new HashMap<>();
        
        //node to be returned
        Node ans = new Node(head.val);
        
        //temproary pointer to the ans node
        Node tempAns = ans;
        
        Node temp = head;
        
        map.put(head,ans);
        temp = temp.next;
        
        
        //loop to store the lookalike new nodes of the original ones
        //create the new list side by side
        while(temp != null){
            Node x = new Node(temp.val);
            map.put(temp,x);
            tempAns.next = x;
            tempAns = x;
            temp = temp.next;
        }
        
        //repointing them to the start
        temp = head;
        tempAns = ans;
        
        //will have lookup of O(1) for the random nodes;
        while(temp!=null){
            tempAns.random = map.get(temp.random);
            tempAns = tempAns.next;
            temp = temp.next;
        }
        
        return ans;
        
    }
}
