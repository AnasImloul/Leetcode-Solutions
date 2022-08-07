var partition = function(head, x) {
    if (!head) {
        return head;
    }
    const less = [];
    const greater = [];
    let concat;
    rec(head);
    return head;
    
    
    function rec(currentNode) {
        if (currentNode.val < x) {
            less.push(currentNode.val);
        } else {
            greater.push(currentNode.val);
        }
        if (!currentNode.next) {
            concat = [...less, ...greater];
            currentNode.val = concat.pop();       
            return;
        }
        rec(currentNode.next);
        currentNode.val = concat.pop();
    }
    
};
