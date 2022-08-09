var hasCycle = function(head) {
    
    let slow = fast = head;
    
    while(fast && fast.next){
        
        slow = slow.next;
        fast = fast.next.next;
        
         if(fast == slow)
            return true;
    }
    return false;
};
