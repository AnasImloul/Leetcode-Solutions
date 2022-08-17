var reverseBetween = function(head, left, right) {
    if(!head)    return null
    let dummy = new ListNode()
    dummy.next = head
    let pre = dummy
    for(let i=0; i<left-1; i++)  pre = pre.next;
    let start = pre.next
    let tmp = start.next
    for(let i=0; i<right-left; i++){
        start.next = tmp.next
        tmp.next = pre.next
        pre.next = tmp
        tmp = start.next
    }
    return dummy.next
};
