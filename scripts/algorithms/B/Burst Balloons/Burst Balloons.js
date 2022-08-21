// Runtime: 616 ms (Top 53.24%) | Memory: 45.6 MB (Top 38.13%)

var rec = function(i,j,arr,dp){
    if(i>j)return 0;
    if(dp[i][j] !== -1)return dp[i][j];
    let max = Number.MIN_VALUE;
    for(let k=i;k<=j;k++){
        let cost = arr[i-1] * arr[k] * arr[j+1] + rec(i,k-1,arr,dp)+rec(k+1,j,arr,dp);
        if(cost>max){
            max = cost
        }
    }
    return dp[i][j] = max
}
var maxCoins = function(nums) {
    let n = nums.length;
    let sol = [];
    for(let i=0;i<n+1;i++){
        sol[i] = Array(n+1).fill(-1)
    }
    nums.unshift(1);
    nums.push(1)
    return rec(1,n,nums,sol)
};