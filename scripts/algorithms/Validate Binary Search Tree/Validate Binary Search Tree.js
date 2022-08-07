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
 * @return {boolean}
 */
var isValidBST = function(root) {
    const nodesToCheck = [{node: root, lowerLimit: -Infinity, upperLimit: Infinity}]
    
    while (nodesToCheck.length > 0) {
        const {node: currentNode, lowerLimit, upperLimit} = nodesToCheck.pop()
        
        if (currentNode.val <= lowerLimit || currentNode.val >= upperLimit) {
            return false
        }
        
        if (currentNode.left) {
            nodesToCheck.push({
                node: currentNode.left,
                lowerLimit,
                upperLimit: currentNode.val
            })
        }
        
        if (currentNode.right) {
            nodesToCheck.push({
                node: currentNode.right,
                lowerLimit: currentNode.val,
                upperLimit
            })
        }
    }
    
    return true
};
