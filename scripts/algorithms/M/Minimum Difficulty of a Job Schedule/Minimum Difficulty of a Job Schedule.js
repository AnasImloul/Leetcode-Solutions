// Runtime: 179 ms (Top 50.62%) | Memory: 42.8 MB (Top 92.59%)
var minDifficulty = function(jobDifficulty, d) {
    // don't have enought jobs to distribute
    if (jobDifficulty.length < d) {
        return -1;
    }

    // in dynamic programming top-down approach
    // we need to have memoisation to not repeat calculations
    let memo = new Array(d+1).fill(-1).map(
        () => new Array(jobDifficulty.length+1).fill(-1)
    )

    const dp = function(D, N) {

        // if we calculated this before, just return
        if (-1 != memo[D][N]) {
            return memo[D][N];
        }

        // if we have only 1 day, we just need to take all jobs
        // and return the highest difficulty
        if (1 == D) {
            memo[D][N] = 0;
            for (let i = 0; i < N; i++) {
                if (memo[D][N] < jobDifficulty[i]) {
                    memo[D][N] = jobDifficulty[i];
                }
            }
            return memo[D][N];
        }

        // otherwise, we use our recurrence relation to calculate
        memo[D][N] = 1000 * D;

        let max_job_per_day = N - D + 1;
        let max_difficulty = 0;

        // iteration for recurrence relation
        for (let X = 1; X <= max_job_per_day; X++) {
            // count max in the current range
            // len - X is the starting point for
            // the last day in D days
            if (jobDifficulty[N - X] > max_difficulty) {
                max_difficulty = jobDifficulty[N - X];
            }
            // recurrence relation
            // we took X jobs,
            // so we still have N - X jobs for D - 1 days
            let min_sum = max_difficulty + dp(D - 1, N - X);

            // pick the min only
            if (min_sum < memo[D][N]) {
                memo[D][N] = min_sum;
            }
        }

        return memo[D][N];
    }

    return dp(d, jobDifficulty.length);
}