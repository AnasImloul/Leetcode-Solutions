var mergeNodes = function(head) {
    let count = 0;
    
    let node = head; // start on first zero
    
    while(node.next) {
        node.val += node.next.val; // add current value to node
        node.next = node.next.next; // remove value between zeroes
        
        // remove last zero
        if(!node.next.next) {
            node.next = null;
            break;
        }
        // traverse node to next 0
        if(node.next.val === 0) {
            node = node.next;
        }
    }
    
    return head;
};```