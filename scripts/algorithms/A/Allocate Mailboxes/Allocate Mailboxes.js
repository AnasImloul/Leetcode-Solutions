// Runtime: 97 ms (Top 81.82%) | Memory: 57.30 MB (Top 9.09%)

/**
 * @param {number[]} houses
 * @param {number} k
 * @return {number}
 */
var minDistance = function(houses, k) {
    let n = houses.length;
    let sorted = houses.sort((a,b)=> a-b)
    costs = new Array(n)
    for (let i = 0; i < n;i++){
        costs[i] = new Array(n).fill(0)
    }
    const memo = new Array(100)
    
    for (let i = 0; i < 100;i++){
        memo[i] = new Array(100)
    }
    
    for (let i = 0 ; i < n ; i++){
        for (let j = 0; j < n ; j++){
            let median = sorted[Math.floor((i+j)/2)]
            for (let t = i; t < j+1; t++){
                costs[i][j] += Math.abs(median - sorted[t])
            }
        }
    }

    const dp = (k, i ) => {
        if (k ===0 && i === n) return 0;
        if (k ===0 || i === n) return Infinity;
        if (memo[k][i] != null) return memo[k][i]
        let ans = Infinity
        for (let j = i; j < n;j++){
            let cost = costs[i][j]
            ans = Math.min(ans , cost + dp(k-1,j+1))
        }
        memo[k][i] = ans
        return ans
    }
    
    return dp(k, 0)
};
