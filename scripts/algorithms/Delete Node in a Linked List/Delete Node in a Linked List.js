var deleteNode = function(node) {
    let nextNode = node.next;
    node.val = nextNode.val;
    node.next = nextNode.next;
};
