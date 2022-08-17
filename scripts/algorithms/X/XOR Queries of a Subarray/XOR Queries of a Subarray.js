var xorQueries = function(arr, queries) {
    let n = arr.length;
    
    while ((n & (n - 1)) != 0) {
        n++;
    }
    
    const len = n;
    const tree = new Array(len * 2).fill(0);
  
    build(tree, 1, 0, len - 1);
    
    const res = [];
    
    for (let i = 0; i < queries.length; i++) {
        const [start, end] = queries[i];
        
        const xor = query(tree, 1, 0, len - 1, start, end);
        
        res.push(xor);
    }
    
    
    return res;
    
   
    function build(tree, segmentIdx, segmentStart, segmentEnd) {
        if (segmentStart === segmentEnd) {
            tree[segmentIdx] = arr[segmentStart];
            return;
        }
        
        const mid = (segmentStart + segmentEnd) >> 1;
        build(tree, segmentIdx * 2, segmentStart, mid);
        build(tree, segmentIdx * 2 + 1, mid + 1, segmentEnd);
        
        tree[segmentIdx] = tree[segmentIdx * 2] ^ tree[segmentIdx * 2 + 1];
		return;
    } 
    
    
    function query(tree, node, nodeStart, nodeEnd, queryStart, queryEnd) {
        if (queryStart <= nodeStart && nodeEnd <= queryEnd) {
            return tree[node];
        }    
        if (nodeEnd < queryStart || queryEnd < nodeStart) {
            return 0;
        }
        
        const mid = (nodeStart + nodeEnd) >> 1;
        
        const leftXor = query(tree, node * 2, nodeStart, mid, queryStart, queryEnd);
        const rightXor = query(tree, node * 2 + 1, mid + 1, nodeEnd, queryStart, queryEnd);
        
        return leftXor ^ rightXor;
    }
};
``