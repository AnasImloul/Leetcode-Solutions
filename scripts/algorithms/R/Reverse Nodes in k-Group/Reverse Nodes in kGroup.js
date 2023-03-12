var reverseKGroup = function(head, k) {
    let count = 0;
    let node = head;
    while (node && count != k) {
        node = node.next;
        count++;
    }
    if (count == k) {
        node = reverseKGroup(node, k);
        while (count > 0) {
            let temp = head.next;
            head.next = node;
            node = head;
            head = temp;
            count--;
        }
        head = node;
    }
    return head;
};
