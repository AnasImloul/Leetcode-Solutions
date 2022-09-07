// Runtime: 153 ms (Top 17.31%) | Memory: 46.2 MB (Top 58.92%)
var levelOrder = function(root) {
    if(!root) return [];

    const Q = [[root, 0]];
    const op = [];

    while(Q.length) {
        const [node, level] = Q.shift();

        if(op.length <= level) {
            op[level] = [];
        }
        op[level].push(node.val);

        for(const child of node.children) {
            Q.push([child, level + 1]);
        }
    }
    return op;
};