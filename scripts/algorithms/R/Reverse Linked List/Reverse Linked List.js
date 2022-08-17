var reverseList = function(head) {
    
    //  Iteratively
    [cur, rev, tmp] = [head, null, null]
    while(cur){
        tmp = cur.next;
        cur.next = rev;
        rev = cur;
        cur = tmp;
        //[current.next, prev, current] = [prev, current, current.next]
    }
}
