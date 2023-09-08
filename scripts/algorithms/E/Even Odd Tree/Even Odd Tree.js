// Runtime: 172 ms (Top 86.4%) | Memory: 104.29 MB (Top 45.7%)

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
 * @return {boolean}
 */
var isEvenOddTree = function(root) {
    let queue = [root];
    let steps = 0;

    while(queue.length>0){
        const currLength = queue.length;
        let nextQueue=[];

        for(let i=0; i<currLength;i++){
            const node = queue[i];
            if(steps%2 !== 0){
                if((i<currLength-1 && node.val<=queue[i+1].val) || node.val%2 !== 0){
                    return false;
                }
            }else if((i<currLength-1 && node.val>=queue[i+1].val)|| node.val%2 === 0){
                return false;
            }
            if(node.left) nextQueue.push(node.left);
            if(node.right) nextQueue.push(node.right);
        }
        queue = nextQueue;
        steps++;
    }

    return true;
};