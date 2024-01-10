// Runtime: 2720 ms (Top 33.33%) | Memory: 213.20 MB (Top 33.33%)

var minimumTotalDistance = function(robot, factory) {
    robot.sort((a, b) => a - b);
    factory.sort((a, b) => a[0] - b[0]);
    let memo = {};
    
    const dp = function(i, j, k) {
        if (memo[`${i} ${j} ${k}`]) return memo[`${i} ${j} ${k}`];
        if (i === robot.length) return 0;
        if (j === factory.length) return Infinity;
        let distance1 = dp(i, j + 1, 0); 
        let distance2 = factory[j][1] > k ? dp(i + 1, j, k + 1) + Math.abs(robot[i] - factory[j][0]) : Infinity;
        const result = Math.min(distance1, distance2);
        memo[`${i} ${j} ${k}`] = result;
        return result;
    }
    
    return dp(0, 0, 0);
};
