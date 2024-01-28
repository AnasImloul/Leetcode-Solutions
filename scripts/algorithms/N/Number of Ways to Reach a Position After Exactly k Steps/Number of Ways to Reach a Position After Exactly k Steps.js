// Runtime: 2587 ms (Top 6.25%) | Memory: 95.80 MB (Top 43.75%)

/**
 * @param {number} startPos
 * @param {number} endPos
 * @param {number} k
 * @return {number}
 */

 const mod= 1e9+7;
 const getKey = (i,j) =>`${i},${j}`;
var numberOfWays = function(startPos, endPos, k) {
    const dp = new Map();
    return solve(startPos, endPos, k, dp);
};

const solve = (start, tar, k, dp) =>{
    if(k<0) return 0;

    if(start ===tar && k===0) return 1;

    if(dp.has(getKey(start, k))) return dp.get(getKey(start,k));

    const ans = (solve(start+1, tar, k-1,dp)%mod + solve(start-1, tar, k-1, dp)%mod)%mod;
    dp.set(getKey(start,k), ans);
    return ans;
}
