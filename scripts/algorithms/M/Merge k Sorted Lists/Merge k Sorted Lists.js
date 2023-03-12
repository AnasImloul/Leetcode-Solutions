var mergeKLists = function(lists) {    
    // Use min heap to keep track of the smallest node in constant time.
    // Enqueue and dequeue will be log(k) where k is the # of lists
    // b/c we only need to keep track of the next node for each list
    // at any given time.
    const minHeap = new MinPriorityQueue({ priority: item => item.val });
    
    for (let head of lists) {
        if (head) minHeap.enqueue(head);
    }
    
    // Create tempHead that we initiate the new list with
    // Final list will start at tempHead.next
    const tempHead = new ListNode();
    let curr = tempHead;
    
    while (!minHeap.isEmpty()) {
        const { val, next } = minHeap.dequeue().element;
        curr.next = new ListNode(val);
        curr = curr.next;
        
        if (next) minHeap.enqueue(next);
    }
    
    return tempHead.next;
};