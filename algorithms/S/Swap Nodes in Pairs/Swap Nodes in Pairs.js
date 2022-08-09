var swapPairs = function(head) {
    if(!head || !head.next)  return head;
    
    // using an array to store all the pairs of the list 
    
    let ptrArr = [];
    let ptr = head;
    
    while(ptr) {
        ptrArr.push(ptr);
        let nptr = ptr.next ? ptr.next.next : null;
        if(nptr) ptr.next.next = null;
        ptr = nptr;
    }
    
    // reversing all the pairs of the list in array
    
    for(let i=0;i<ptrArr.length;i++) {
        let node = ptrArr[i];
        let temp = node.next;
        
        if(!temp) break;
        temp.next = node;
        node.next = null;
        ptrArr[i] = temp;
    }
    
    let dummy = new ListNode(-1);
    let nptr = dummy;
    
    // joining all the pairs back again
    ptrArr.forEach(ele => {
        nptr.next = ele;
        nptr = nptr.next.next;
    })
    
    return dummy.next;
    
};
