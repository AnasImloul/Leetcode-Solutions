var reverseKGroup = function(head, k) {
    if(head === null) return head
    
    let next = null
    let prev = null
    let curr = head
    let i = 0
    
    while(curr) {
        i++
        curr = curr.next
    }
    
    if(i<k) return head
    
    i = 0
    curr = head
    
    while(curr !== null && i<k) {
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
        i++
    }
    
    if(curr !== null) {
        head.next = reverseKGroup(next,k)
    }
    
    return prev
};
