// Runtime: 166 ms (Top 48.15%) | Memory: 52.1 MB (Top 16.67%)
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 * this.val = (val===undefined ? 0 : val)
 * this.left = (left===undefined ? null : left)
 * this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */
var FindElements = function(root) {
    this.st = new Set()

    recover = (root, val) =>{
    this.st.add(val);
    if(root.left != null) recover(root.left, val * 2 + 1)
    if(root.right != null) recover(root.right, val * 2 + 2)
    }

    recover(root, 0)
};

/**
 * @param {number} target
 * @return {boolean}
 */
FindElements.prototype.find = function(target) {
    return this.st.has(target)
};

/**
 * Your FindElements object will be instantiated and called as such:
 * var obj = new FindElements(root)
 * var param_1 = obj.find(target)
 */