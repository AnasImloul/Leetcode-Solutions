var reverseKGroup = function(head, k) {
    const helper = (node) => {
        let ptr = node;
        
        let t = k;
        let prev = null;
        
        while(t && ptr) {
            prev = ptr;
            ptr = ptr.next;
            t -= 1;
        }
        
        if(t > 0) //if k is not zero then do not reverse, simply return;
            return node;
        
        let f = prev.next;
        prev.next = null;
        
        let [rev, end] = reverseList(node);
        
        end.next = helper(f);
        
        return rev;
    }
    
    return helper(head);
};

var reverseList = function(head) {
        let prev = null;
        let current = head;
        let end = head;

        while(current) {
            let next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return [prev, end];
 };
