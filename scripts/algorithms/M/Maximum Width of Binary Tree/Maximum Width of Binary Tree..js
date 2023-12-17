// Runtime: 66 ms (Top 53.29%) | Memory: 47.20 MB (Top 43.11%)

var widthOfBinaryTree = function(root) {
    if(!root) {
        return 0;
    }
    const q = [[root, 0]];
    let maxWidth = 0, l = 0, r = 0;
    while(q.length) {
        const size = q.length;
        const startIdx = q[0][1];
        for(let i = 0; i < size; ++i) {
            const [node, idx] = q.shift();
            if(i === 0) {
                l = idx;
            }
            if(i === size - 1) {
                r = idx;
            }
			const subIdx = idx - startIdx;
            if(node.left !== null) {
                q.push([node.left, 2 * subIdx + 1]);
            }
            if(node.right !== null) {
                q.push([node.right, 2 * subIdx + 2]);
            }
        }
        maxWidth = Math.max(maxWidth, r - l + 1);
    }
    return maxWidth;
};
