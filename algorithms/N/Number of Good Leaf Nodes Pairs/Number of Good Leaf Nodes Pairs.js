let parentMap;
let leaves;
var countPairs = function(root, distance) {
    if(root==null){
        return 0;
    }
    leaves = [];
    parentMap = new Map();
    let cnt = 0;
    let visited;
    
    // Step1: build parent map
    findParent(root, null);
    
    // Step2: dfs to find all leafNodes
    dfs1(root);
     
    // Step3: count pairs from each leaf
    for(const leaf of leaves)
    {
        visited = new Set();
        cnt += dfs2(leaf, 0, distance, visited);
    }
    
    return cnt / 2; 
};

function findParent(node, pa) {
    if(node === null) {
        return;
    }
    parentMap.set(node, pa);
    findParent(node.left, node);
    findParent(node.right, node); 
}
function dfs1(node) {
    if(node===null) {
        return;
    }
    if(node.left===null && node.right === null) {
        leaves.push(node);
        return;
    }
    dfs1(node.left);
    dfs1(node.right);
}

function dfs2(node, cur, dist, visited)
{
    if(!node || cur > dist || visited.has(node) ) {
        return 0;
    }

    if(node.left === null && node.right===null && cur !== 0) {
        return 1;
    }
     
    visited.add(node);
    let ans = 0;
    ans += dfs2(parentMap.get(node), cur+1, dist, visited);
    ans += dfs2(node.left, cur+1, dist, visited);
    ans += dfs2(node.right, cur+1, dist, visited);
    return ans;  
}
