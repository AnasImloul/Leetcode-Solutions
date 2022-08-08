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
 */
var CBTInserter = function(root) {
    this.root = root;
};

/** 
 * @param {number} val
 * @return {number}
 */
CBTInserter.prototype.insert = function(val) {
    let cur = this.root;
    let queue = [cur];
    while(queue.length){
        let updatedQueue = [];
        while(queue.length){
            let node = queue.shift();
            if(!node.left) {
                node.left = new TreeNode(val);
                return node.val;
            }
            else updatedQueue.push(node.left);
            if(!node.right) {
                node.right = new TreeNode(val);
                return node.val;
            }
            else updatedQueue.push(node.right);
        }
        queue = updatedQueue ;
    }
    
};

/**
 * @return {TreeNode}
 */
CBTInserter.prototype.get_root = function() {
    return this.root;
};

/** 
 * Your CBTInserter object will be instantiated and called as such:
 * var obj = new CBTInserter(root)
 * var param_1 = obj.insert(val)
 * var param_2 = obj.get_root()
 */
