// Runtime: 110 ms (Top 40.72%) | Memory: 44.9 MB (Top 15.23%)
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
 * @return {number[][]}
 */
var verticalTraversal = function(root) {
    let ans = [];
    let l = 0, ri = 0, mi = 0;
    const preOrder = (r = root, mid = 0, d = 0) => {
        if(!r) return ;

        if(mid == 0) {
            if(ans.length < mi + 1) ans.push([]);
            ans[mi].push({v: r.val, d});
        } else if(mid < 0) {
           if(mid < l) {
               l = mid;
               mi++;
               ans.unshift([{v: r.val, d}]);
           } else {
               let idx = mi + mid;
               ans[idx].push({v: r.val, d});
           }
        } else {
            if(mid > ri) {
                ri = mid;
                ans.push([{v: r.val, d}]);
            } else {
                let idx = mi + mid;
                ans[idx].push({v: r.val, d});
            }
        }

        preOrder(r.left, mid - 1, d + 1);
        preOrder(r.right, mid + 1, d + 1);
    }
    preOrder();
    const sortByDepthOrVal = (a, b) => {
        if(a.d == b.d) return a.v - b.v;
        return a.d - b.d;
    }
    ans = ans.map(col => col.sort(sortByDepthOrVal).map(a => a.v));
    return ans;
};