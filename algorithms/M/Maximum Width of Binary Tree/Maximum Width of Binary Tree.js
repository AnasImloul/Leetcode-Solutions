/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var widthOfBinaryTree = function(root) {
    if (!root) return 0;

    let res = 0, row = [[root, 0]];
    while (row.length > 0) {
        const nextRow = [];
        let curStart = -1, curEnd = -2;
        for (let i = 0; i < row.length; i++) {
            const [node, index] = row[i];
            if (curStart === -1) {
                curStart = index;
            }
            
            curEnd = index;
            
            if (node.left) {
                nextRow.push([node.left, index*2]);
            }
            
            if (node.right) {
                nextRow.push([node.right, index*2 + 1]);
            }
        }
        
        res = Math.max(res, curEnd - curStart + 1);
        if (nextRow.length === 1) {
            nextRow[0][1] = 0;
        }
        row = nextRow;
    }
    
    return res;
};