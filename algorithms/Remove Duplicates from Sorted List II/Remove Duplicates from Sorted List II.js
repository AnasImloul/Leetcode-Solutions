var deleteDuplicates = function(head) {
    
    let map = new Map()
    let result = new ListNode(-1)
    
    let newCurr = result
    let curr = head
    
    while(head){
        if(map.has(head.val)){
            map.set(head.val, 2)
        }else{
            newArr.push(head.val)
            map.set(head.val, 1)
        }
        head = head.next
    }
    
    while(curr){
        if(map.get(curr.val) !== 2){
            newCurr.next = new ListNode(curr.val)
            newCurr = newCurr.next
        }
        curr = curr.next
    }
    
    return result.next
};
