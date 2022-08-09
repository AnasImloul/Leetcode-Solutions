var minSideJumps = function(obstacles) {
    // create a dp cache for tabulation
    const dp = [...obstacles].map(() => new Array(4).fill(Infinity));
    
    // initialize the first positions
    dp[0][2] = 0;
    for (const lane of [1,3]) {
        if (obstacles[0] === lane) continue;
        dp[0][lane] = 1;
    }

    // for every index we will do the following
    for (let i = 1; i < obstacles.length; i++) {
        
        // first we find the best way to get to this position from the previous index
        for (let nextLane = 1; nextLane <= 3; nextLane++) {
            if (obstacles[i] === nextLane) continue;
            dp[i][nextLane] = dp[i - 1][nextLane]
        }
        
        // then we find the best way to get to this position from the current index;
        for (let nextLane = 1; nextLane <= 3; nextLane++) {
            for (let prevLane = 1; prevLane <= 3; prevLane++) {
                if (prevLane === nextLane) continue;
                if (obstacles[i] === nextLane) continue;
                dp[i][nextLane] = Math.min(dp[i][nextLane], dp[i][prevLane] + 1)
            }
        }
    }

    // return the best result after reaching the end
    return Math.min(...dp[dp.length - 1])
};
