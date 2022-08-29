// Runtime: 338 ms (Top 66.67%) | Memory: 73.8 MB (Top 33.33%)
var minSkips = function(dist, speed, hoursBefore) {

    // calculates the time needed to rest
    const getRestTime = (timeFinished) => {
        if (timeFinished === Infinity) return 0;
        return (speed - (timeFinished % speed)) % speed;
    }

    // dp is a n x n matrix with
    // dp[destinationIndex][numRestsSkipped] = timeTaken
    //
    // destinationIndex: the index of the destination being observed
    // numRestsSkipped: number of rests taken
    // timeTaken: minimum time taken to travel to destination taking numRests number of rests
    const dp = [...dist].map(() => new Array(dist.length).fill(Infinity));

    // start with the first stop
    dp[0][0] = dist[0] + getRestTime(dist[0]) // took a rest at the first destination
    dp[0][1] = dist[0]; // did not take a rest at the first destination

    for (let distIdx = 1; distIdx < dist.length; distIdx++) {
        const distance = dist[distIdx];
        let timeToDestWithoutrest = dp[distIdx - 1][0] + distance;
        dp[distIdx][0] = timeToDestWithoutrest + getRestTime(timeToDestWithoutrest);
        for (let numRestsSkipped = 1; numRestsSkipped <= distIdx + 1; numRestsSkipped++) {
            // calculate the time if taking a rest here
            timeToDestWithoutrest = dp[distIdx - 1][numRestsSkipped] + distance;
            const didRestTimeToDest = timeToDestWithoutrest + getRestTime(timeToDestWithoutrest);

            // calculate the time without resting here
            const didntRestTimeToDest = dp[distIdx - 1][numRestsSkipped - 1] + distance

            // store the best time in the dp
            dp[distIdx][numRestsSkipped] = Math.min(dp[distIdx][numRestsSkipped],
                                                    didRestTimeToDest,
                                                    didntRestTimeToDest);
        }
    }

    // find the minimum number of rests visiting all the destinations
    const speedHours = speed * hoursBefore;
    for (let numRests = 0; numRests < dist.length; numRests++) {
        if (dp[dist.length - 1][numRests] <= speedHours) {
            return numRests;
        }
    }
    return -1;
};