// Runtime: 194 ms (Top 50.00%) | Memory: 46.5 MB (Top 62.50%)
var shortestSuperstring = function(words) {
    let N = words.length, suffixes = new Map(),
        edges = Array.from({length: N}, () => new Uint8Array(N))

    // Build the edge graph
    for (let i = 0, word = words; i < N; i++) {
        let word = words[i]
        for (let k = 1; k < word.length; k++) {
            let sub = word.slice(k)
            if (suffixes.has(sub)) suffixes.get(sub).push(i)
            else suffixes.set(sub, [i])
        }
    }
    for (let j = 0; j < N; j++) {
        let word = words[j]
        for (let k = 1; k < word.length; k++) {
            let sub = word.slice(0,k)
            if (suffixes.has(sub))
                for (let i of suffixes.get(sub))
                    edges[i][j] = Math.max(edges[i][j], k)
        }
    }

    // Initialize DP array
    let M = N - 1,
        dp = Array.from({length: M}, () => new Uint16Array(1 << M))

    // Helper function to find the best value for dp[curr][currSet]
    // Store the previous node with bit manipulation for backtracking
    const solve = (curr, currSet) => {
        let prevSet = currSet - (1 << curr), bestOverlap = 0, bestPrev
        if (!prevSet) return (edges[M][curr] << 4) + M
        for (let prev = 0; prev < M; prev++)
            if (prevSet & 1 << prev) {
                let overlap = edges[prev][curr] + (dp[prev][prevSet] >> 4)
                if (overlap >= bestOverlap)
                    bestOverlap = overlap, bestPrev = prev
            }
        return (bestOverlap << 4) + bestPrev
    }

    // Build DP using solve
    for (let currSet = 1; currSet < 1 << M; currSet++)
        for (let curr = 0; curr < N; curr++)
            if (currSet & 1 << curr)
                dp[curr][currSet] = solve(curr, currSet)

    // Join the ends at index M
    let curr = solve(M, (1 << N) - 1) & (1 << 4) - 1

    // Build the circle by backtracking path info from dp
    // and find the best place to cut the circle
    let path = [curr], currSet = (1 << M) - 1,
        bestStart = 0, lowOverlap = edges[curr][M], prev
    while (curr !== M) {
        prev = dp[curr][currSet] & (1 << 4) - 1, currSet -= 1 << curr
        let overlap = edges[prev][curr]
        if (overlap < lowOverlap)
            lowOverlap = overlap, bestStart = N - path.length
        curr = prev, path.unshift(curr)
    }

    // Build and return ans by cutting the circle at bestStart
    let ans = []
    for (let i = bestStart; i < bestStart + M; i++) {
        let curr = path[i%N], next = path[(i+1)%N], word = words[curr]
        ans.push(word.slice(0, word.length - edges[curr][next]))
    }
    ans.push(words[path[(bestStart+M)%N]])
    return ans.join("")
};