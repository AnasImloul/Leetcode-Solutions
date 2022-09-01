// Runtime: 132 ms (Top 76.39%) | Memory: 44.5 MB (Top 80.56%)
var findTheCity = function(n, edges, distanceThreshold) {
    const dp = Array.from({length: n}, (_, i) => {
        return Array.from({length: n}, (_, j) => i == j ? 0 : Infinity)
    });

    for(let edge of edges) {
        const [a, b, w] = edge;
        dp[a][b] = dp[b][a] = w;
    }

    // k is intermediate node
    for(let k = 0; k < n; k++) {
        // fix distances from i to other nodes with k as intermediate
        for(let i = 0; i < n; i++) {
            if(i == k || dp[i][k] == Infinity) continue;
            for(let j = i + 1; j < n; j++) {
                dp[i][j] = dp[j][i] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    };

    let city = -1, minCity = n;
    for(let i = 0; i < n; i++) {
        let count = 0;
        for(let j = 0; j < n; j++) {
            if(i == j) continue;
            if(dp[i][j] <= distanceThreshold) count++;
        }
        if(count <= minCity) {
            minCity = count;
            city = i;
        }
    }

    return city;
};