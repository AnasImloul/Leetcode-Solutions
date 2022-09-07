// Runtime: 84 ms (Top 74.03%) | Memory: 44.7 MB (Top 28.29%)
/*
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 * this.val = (val===undefined ? 0 : val)
 * this.left = (left===undefined ? null : left)
 * this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */

var leafSimilar = function(root1, root2) {
    let array1 = [], array2 = [];
    let leaf1 = getLeaf(root1, array1),
        leaf2 = getLeaf(root2, array2);

    if (leaf1.length !== leaf2.length){ // if different lengths, return false right away
        return false;
    }

    for(let i = 0; i < leaf1.length; i++){
        if (leaf1[i] !== leaf2[i]){ // compare pair by pair
            return false;
        }
    }

    return true;
};

var getLeaf = function(root, array){ // DFS
    if (!root){
        return;
    }
    if (!(root.left || root.right)){
        array.push(root.val); // push leaf value to the array
    }
    getLeaf(root.left, array);
    getLeaf(root.right, array);

    return array;
}