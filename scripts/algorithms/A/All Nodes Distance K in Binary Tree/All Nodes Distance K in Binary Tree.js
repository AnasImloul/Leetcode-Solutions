// Runtime: 139 ms (Top 9.47%) | Memory: 44.8 MB (Top 45.88%)
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 * this.val = val;
 * this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} target
 * @param {number} k
 * @return {number[]}
 */
var distanceK = function(root, target, k) {
    if(k === 0)
        return [target.val];

    let res = [];

    const helper = (node, k, bool) => {
        if(node === null)
            return [false, 0];

        if(k === 0 && node.val !== target.val) {
            res.push(node.val);
            return null;
        }

        if(bool) {
            helper(node.left, k - 1, bool);
            helper(node.right, k - 1, bool);
            return null;
        }

        if(node.val === target.val) {
           //Here nodes of k distance are at bottom
            helper(node.left, k - 1, true);
            helper(node.right, k - 1, true);
            return [true, 1];
        } else {

            let [l, d] = helper(node.left, k, false);

             //Found target node on left side, now get nodes of k distance from right side as well
            if(l === true) {
                if(k - d === 0) //for current node
                    res.push(node.val);
                helper(node.right, k - d - 1, true);
                return [true, d + 1];
            }

            let [r, d1] = helper(node.right, k, false);

            if(r === true) {
                if(k - d1 === 0)
                    res.push(node.val);
                helper(node.left, k - d1 - 1, true);
                return [true, d1 + 1];
            }

            return [false, 0];
        }

    }

    helper(root, k, false);

    return res;
};
