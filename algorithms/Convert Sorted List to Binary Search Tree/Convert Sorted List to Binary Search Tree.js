var sortedListToBST = function(head) {
    if(!head) return null;
    if(!head.next) return new TreeNode(head.val);
    
    let fast = head, slow = head, prev = head;
    while(fast && fast.next) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
    
    const root = new TreeNode(slow.val);
    prev.next = null;
    
    const newHead = slow.next;
    slow.next = null;
    
    root.left = sortedListToBST(head);
    root.right = sortedListToBST(newHead);
    
    return root;
};
