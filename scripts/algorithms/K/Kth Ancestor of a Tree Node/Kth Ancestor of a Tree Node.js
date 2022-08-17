/**
 * @param {number} n
 * @param {number[]} parent
 */
var TreeAncestor = function(n, parent) {
    this.n = n;
    this.parent = parent;
};

/** 
 * @param {number} node 
 * @param {number} k
 * @return {number}
 */

/*
Qs:
1. Is the given tree a binary tree or n-ary tree?
2. Can k be greater than possible (the total number of ancestors of given node)?

Every node has a parent except the root.
1. Check if given node has a parent. If not, return -1.
2. Set given node as the current ancestor and start a while loop which continues while k is greater than 0.
At each iteration, we set `ancestor` to the parent of current `ancestor` and decrement k. If k is still greater
than 0 but ancestor is -1, that means k is greater than possible. Hence, we return -1. Else, while loop will
end when we are at the correct k-th ancestor. We return ancestor.
*/
TreeAncestor.prototype.getKthAncestor = function(node, k) {
    // check if given node has a parent
    if (this.parent[node] === -1) return -1;
    let ancestor = node;
    while (k > 0) {
        if (ancestor === -1) return -1; // k is greater than total number of ancestors of given node
        ancestor = this.parent[ancestor];
        k--;
    }
    return ancestor;
    // T.C: O(k)
};
