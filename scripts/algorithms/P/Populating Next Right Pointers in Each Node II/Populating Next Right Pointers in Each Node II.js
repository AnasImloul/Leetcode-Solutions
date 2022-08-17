var connect = function(root) {
    let curr = root;
    
    while (curr != null) {
        let start = null; // (1)
        let prev = null;
    
        while (curr != null) { // (2)
            if (start == null) { // (3)
                if (curr.left) start = curr.left;
                else if (curr.right) start = curr.right;
                
                prev = start; // (4)
            }
            
            if (prev != null) {
                if (curr.left && prev != curr.left) {
                    prev = prev.next = curr.left; // (5)
                }
                if (curr.right && prev != curr.right) {
                    prev = prev.next = curr.right;
                }
            }

            curr = curr.next; // (6)
        }
		
        curr = start; // (7)
    }
    
    return root;
};
