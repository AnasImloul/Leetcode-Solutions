var removeZeroSumSublists = function(head) {
    const dummyHead = new ListNode();
    dummyHead.next = head;
    let prev = dummyHead;
    let start = head;
    
    while (start != null) {
        let sum = 0;
        let tail = start;
        
        while (tail != null) {
            sum += tail.val;
            if (sum === 0) break;
            tail = tail.next;
        }
        
        if (tail) {
            prev.next = tail.next;
            start = tail.next;
        }
        else {
            prev = start;
            start = start.next;
        }
    }
    
    
    return dummyHead.next;
};
