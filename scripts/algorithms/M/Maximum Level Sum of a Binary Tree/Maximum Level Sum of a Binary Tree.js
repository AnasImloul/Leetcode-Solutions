// Runtime: 216 ms (Top 61.88%) | Memory: 76.2 MB (Top 22.10%)
var maxLevelSum = function(root) {
    let res;
    let maxSum = -Infinity;
    let currLevel = 1;

    const queue = [root];

    while (queue.length) {
        let levelSize = queue.length;
        let levelSum = 0;

        for (let i = 0; i < levelSize; i++) {
            let curr = queue.shift();
            levelSum += curr.val;

            if (curr.left) queue.push(curr.left);
            if (curr.right) queue.push(curr.right);
        }

        if (maxSum < levelSum) {
            res = currLevel;
            maxSum = levelSum
        }

        currLevel++;
    }

    return res;
};