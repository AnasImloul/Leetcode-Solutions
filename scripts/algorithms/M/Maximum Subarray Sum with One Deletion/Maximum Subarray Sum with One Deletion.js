/**
 * @param {number[]} arr
 * @return {number}
 */
 

// var maximumSum = function(arr) {
//     const len = arr.length;
//     const dp = new Array(len).fill(() => [null, null]);
//     dp[0][0] = arr[0];
//     dp[0][1] = 0;
//     let result = arr[0];
//     for(let i = 1; i < len; i++) {
//         dp[i][1] = Math.max(dp[i-1][1] + arr[i], dp[i-1][0]);
//         dp[i][0] = Math.max(dp[i-1][0] + arr[i], arr[i]);
//         result = Math.max(result, Math.max(dp[i][0], dp[i][1]));  
//     }
    
//     return result;
// };

// optimization
var maximumSum = function(arr) {
    let noDelete = arr[0], oneDelete = 0, max = arr[0];
    for(let i = 1; i < arr.length; i++) {
        oneDelete = Math.max(oneDelete + arr[i], noDelete);
        noDelete = Math.max(noDelete + arr[i], arr[i]);
        max = Math.max(max, Math.max(noDelete, oneDelete));
    }
    return max;
};