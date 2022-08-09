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
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function(root) {
    let stack = [];
    let result = [];
    let hashTable = {};
    stack.push(root);
    while (stack.length) {
        let node = stack.pop();
        let treeToArr = dfsArr(node);
        if (node.right) {
            stack.push(node.right);
        }
        if (node.left) {
            stack.push(node.left);
        }
		// If sub tree has not been seen, set to one.
		// If sub tree has been seen, increment number.
        hashTable[treeToArr] = hashTable[treeToArr] ? 
            { num: hashTable[treeToArr].num + 1, ref: node} :
            { num: 1, ref: node};
    }
	// Builds result array with duplicate trees seen
    for (let i in hashTable) {
        if (hashTable[i].num > 1) {
            result.push(hashTable[i].ref);
        }
    }
    return result;
};

// Post order of subtree stored in array
function dfsArr (node) {
    let stack = [];
    let result = [];
    stack.push(node);
    while (stack.length) {
        let node = stack.pop();
        node ? result.push(node.val) : result.push(null);
        if (!node) continue;
        if (node.right) {
            stack.push(node.right);
        } else {
            stack.push(null);
        }
        if (node.left) {
            stack.push(node.left);
        } else {
            stack.push(null);
        }
    }
    return result;
}
