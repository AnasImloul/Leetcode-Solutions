var reverseEvenLengthGroups = function(head) {
    let groupSize = 2;

    let start = head;

    let prev = head;
    let curr = head.next;

    let count = 0;
    
    while (curr != null) {
        if (count === groupSize) {
            if (groupSize % 2 === 0) { // we only reverse when it is even
                const end = curr;
                const tail = start.next; // the starting node of the reverse linked list will be the tail after the reverse takes place
                reverseList(start, end, count); // we need to reverse everything in the middle of start and end 
                start = tail; // we set the new start to the end of the reversed linked list
            }
            else { // when groupSize is even we don't need to reverse, but need to set the new start to the prev node
                start = prev;
            }
            count = 0; // whenever we reached the group size we need to reset our count and up our groupSize
            ++groupSize;
        }
        else { // just a normal traversal when we haven't hit our groupSize
            prev = curr;        
            curr = curr.next;
            ++count;
        }
    }
   
    if (count % 2 === 0) { // in the case where we ended early on even count
         reverseList(start, null, count);
    }
    
    return head;
    
    
    function reverseList(start, end, count) {
        if (start.next == null) return start; // for case when we have a single node
        
        let prev = start;
        
        let curr = start.next;
        let tail = start.next;
        
        for (let i = 0; i < count; ++i) {
            const next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        
        start.next = prev;
        tail.next = end;
        
        return ;
    }
};
