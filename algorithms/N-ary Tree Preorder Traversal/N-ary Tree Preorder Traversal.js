var preorder = function(root) {
    return [root.val].concat(root.children.map( (c)=>c ? preorder(c) : [] ).flat() );
};
