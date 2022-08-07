 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var connect = function(root) {
    
    if(!root || !root.left || !root.right){
       return root;
     }
    
     root.left.next = root.right;
     if(root.next){
         root.right.next = root.next.left;
     } else{
         root.right.next = null;
     }

    root.left = connect(root.left);
    root.right = connect(root.right);
    
    return root;
    
};