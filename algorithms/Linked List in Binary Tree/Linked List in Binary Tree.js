var isSubPath = function(head, root) {
    if(!root)    return false
    if(issame(head, root))  return true
    return isSubPath(head, root.left) || isSubPath(head, root.right)
};

function issame(head, root){
    if(!head)   return true
    if(!root)   return false
    if(head.val != root.val)    return false
    return issame(head.next, root.left) || issame(head.next, root.right)
};
