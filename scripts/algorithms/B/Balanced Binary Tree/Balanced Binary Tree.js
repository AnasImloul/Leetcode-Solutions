// Runtime: 112 ms (Top 53.69%) | Memory: 46.9 MB (Top 82.53%)
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
 * @return {boolean}
 */
var isBalanced = function(root) {

    let result=true;
    function Dfs(root){
        if(!root)return 0;
        let left=Dfs(root.left)
        let right=Dfs(root.right)
        if(Math.abs(left-right)>1){result=false ;return;}
        return 1+Math.max(left,right)
    }
    Dfs(root)
    return result
};
