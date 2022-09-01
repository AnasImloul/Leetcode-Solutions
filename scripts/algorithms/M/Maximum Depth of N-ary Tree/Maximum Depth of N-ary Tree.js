// Runtime: 106 ms (Top 57.76%) | Memory: 45.2 MB (Top 47.13%)
/**
 * // Definition for a Node.
 * function Node(val,children) {
 * this.val = val;
 * this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number}
 */
var maxDepth = function(root) {
  let max = 0;

  if (!root) {
    return max;
  }

  const search = (root, index) => {
    max = Math.max(index, max);

    if (root?.children && root?.children.length > 0) {
      for (let i = 0; i < root.children.length; i++) {
        search(root.children[i], index+1);
      }
    }
  }

  search(root, 1);

  return max;
};