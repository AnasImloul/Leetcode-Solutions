

var binaryTreePaths = function(root) {
    if ( root === null ) {
        return [];
    }
    const lPath = binaryTreePaths(root.left);
    const rPath = binaryTreePaths(root.right);
    if ( lPath.length === 0 && rPath.length === 0 ) return ["" + root.val];

    if ( lPath.length > 0 )
        for ( let i = 0; i < lPath.length; i++ )
            lPath[i] = root.val + "->" + lPath[i];
    if ( rPath.length > 0 )
        for ( let i = 0; i < rPath.length; i++ )
            rPath[i] = root.val + "->" + rPath[i];
    return lPath.concat(rPath);
};


