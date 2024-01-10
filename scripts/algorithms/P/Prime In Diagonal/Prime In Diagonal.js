// Runtime: 73 ms (Top 51.61%) | Memory: 50.10 MB (Top 48.39%)

/**
 * @param {number[][]} nums
 * @return {number}
 */

var isprime=(n)=>{
    if(n===1) return 0;
    for(var i=2;i*i<=n; i++){
        if(n%i===0) return 0;
    }
    return 1;
}
    
   
var diagonalPrime = function(nums) {
    var n=nums.length,mx=0;
    for(var i=0;i<n;i++){
        for(var j=0;j<n;j++){
            if(i==j && isprime(nums[i][j])) mx=Math.max(mx,nums[i][j]);
            if(j==n-i-1 &&  isprime(nums[i][j])) mx=Math.max(mx,nums[i][j]);
        }
    }
    return mx;
};
