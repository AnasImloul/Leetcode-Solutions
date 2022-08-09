var deepestLeavesSum = function(root) {
    let queue = [];
    queue.push([root, 0]);
    let sum = 0;
    let curLevel = 0
    let i = 0;
    while(queue.length-i > 0) {
        let [node, level] = queue[i];
        queue[i] = null;
        i++;
        if(level > curLevel) {
            sum = 0;
            curLevel = level;
        }
        sum += node.val;
        if(node.left != null) queue.push([node.left, level+1]);
        if(node.right != null) queue.push([node.right, level+1]);
    }
    return sum;
    //time: o(n)
    //space: o(n)
};
