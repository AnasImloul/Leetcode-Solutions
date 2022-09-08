// Runtime: 109 ms (Top 52.36%) | Memory: 47.7 MB (Top 20.94%)
var rob = function(root) {
    const dfs = (node = root) => {
        if (!node || node.val === null) return [0, 0];
        const { val, left, right } = node;
        const [robL, notRobL] = dfs(left);
        const [robR, notRobR] = dfs(right);
        const rob = val + notRobL + notRobR;
        const notRob = Math.max(robL, notRobL) + Math.max(robR, notRobR);

        return [rob, notRob];
    };

    return Math.max(...dfs());
};