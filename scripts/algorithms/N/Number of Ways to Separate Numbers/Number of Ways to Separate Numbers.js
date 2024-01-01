// Runtime: 257 ms (Top 75.0%) | Memory: 169.60 MB (Top 50.0%)

const MOD = 10**9 + 7;
var numberOfCombinations = function(num) {
    const n = num.length;
    const counts = Array.from({length: n}, () => new Array(n+1).fill(0));
    const allSameFlag = num.split('').every(c => c === num[0]);
    for (let i = 0; i < n; i++) {
        counts[i][n] = num[i] !== '0' ? 1 : 0;
    }
    
    const partialCompare = (i, j) => {
        if (i === j || allSameFlag) {
            return 0;
        } else if (num[i] !== num[j]) {
            return num[i] > num[j] ? i+1 : -(i+1);
        } else if (2*j - i === n || 2*j - i === n-1) {
            for (let k = 0; k < j-i; k++) {
                if (num[i+k] !== num[j+k]) {
                    return num[i+k] > num[j+k] ? i+k : -(i+k+1);
                }
            }
            return 0;
        } else {
            const idx = partialCompare(i+1, j+1);
            return idx===0 ? 0 : Math.abs(idx)-1 >= j ? 0 : idx;
        }
    }
    
    let ans = counts[0][n];
    for (let j = n-1; j > 0; j--) {
        let k = n, total = 0;
        for (let i = 0; i < j; i++) {
            if (num[i] !== '0') {
                while (k-j > j-i || (k-j === j-i && partialCompare(i, j) <= 0)) {
                    total = (total + counts[j][k]) % MOD;
                    k--;
                }
                counts[i][j] = total;
            }
        }
        ans = (ans + counts[0][j]) % MOD;
        counts.pop();
    }
    return ans;
};
