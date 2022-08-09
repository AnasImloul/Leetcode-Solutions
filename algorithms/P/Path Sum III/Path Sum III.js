var pathSum = function(root, targetSum) {
let count = 0;

let hasSum = (node, target) => { //helper function, calculates number of paths having sum equal to target starting from given node
    if(node===null){// base case
        return;
    }
    if(node.val===target){// if at any point path sum meets the requirement
        count++;
    }
    //recursive call
    hasSum(node.left, target-node.val);
    hasSum(node.right, target-node.val);
}

let dfs = (node) => {//dfs on every node and find sum equal to target starting from every node
    if(node===null)
        return;
    dfs(node.left);
    dfs(node.right);
    hasSum(node,targetSum);// find sum of path starting on this point
}

dfs(root);

return count;
};