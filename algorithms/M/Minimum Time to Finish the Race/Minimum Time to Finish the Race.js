var minimumFinishTime = function(tires, changeTime, numLaps) {  
    const n = tires.length
    const smallestTire = Math.min(...tires.map(t => t[1]))
    const maxSameTire = Math.floor(Math.log(changeTime) / Math.log(smallestTire)) + 1
    const sameTireLast = Array(n).fill(0)
	
	// DP array tracking what is the min cost to complete lap i using same tire
    const sameTire = Array(maxSameTire + 1).fill(Infinity)
    for (let lap = 1; lap <= maxSameTire; lap++) {
        tires.forEach((tire, i) => {
            sameTireLast[i] += tire[0] * tire[1] ** (lap - 1)
            sameTire[lap] = Math.min(sameTire[lap], sameTireLast[i])
        })
    }
    
    const dp = Array(numLaps + 1).fill(Infinity)
    for (let i = 1; i < numLaps + 1; i++) {
        if (i <= maxSameTire) dp[i] = sameTire[i]
		// at each lap, we can either use the same tire up to this lap (sameTire[i])
		// or a combination of 2 different best times, 
		// eg lap 6: use best time from lap 3 + lap 3
		// or from lap 4 + lap 2
		// or lap 5 + lap 1
        for (let j = 1; j < i / 2 + 1; j++) {
            dp[i] = Math.min(dp[i], dp[i-j] + changeTime + dp[j])
        }
    }
    return dp[numLaps]
};
