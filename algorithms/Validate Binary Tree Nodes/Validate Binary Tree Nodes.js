var validateBinaryTreeNodes = function(n, leftChild, rightChild) {
	// find in-degree for each node
    const inDeg = new Array(n).fill(0);
    for(let i = 0; i < n; ++i) {
        if(leftChild[i] !== -1) {
            ++inDeg[leftChild[i]];    
        }
        if(rightChild[i] !== -1) {
            ++inDeg[rightChild[i]];
        }
    }
	// find the root node and check each node has only one in-degree
    let rootNodeId = -1;
    for(let i = 0; i < n; ++i) {
        if(inDeg[i] === 0) {
            rootNodeId = i;
        } else if(inDeg[i] > 1) {
            return false;
        }
    }
	// if no root node found -> invalid BT
    if(rootNodeId === -1) {
        return false;
    }
	// BFS to check that each node is visited at least and at most once
    const visited = new Set();
    const queue = [rootNodeId];
    
    while(queue.length) {
        const nodeId = queue.shift();
        
        if(visited.has(nodeId)) {
            return false;
        }
        visited.add(nodeId);
        
       const leftNode = leftChild[nodeId],
             rightNode = rightChild[nodeId];
        if(leftNode !== -1) {
            queue.push(leftNode);
        }
        if(rightNode !== -1) {
            queue.push(rightNode);
        }
    }
	// checking each node is visited at least once
    return visited.size === n;};
