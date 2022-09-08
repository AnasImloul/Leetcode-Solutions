// Runtime: 183 ms (Top 40.91%) | Memory: 47.7 MB (Top 22.73%)
var maxJumps = function(arr, d) {

    let n = arr.length;
    let dp = new Array(n).fill(0);
    let result = 0;

    // Time complexity:
    // O(nlogn) + O(n*d) => O(ologn)

    // First we sort the arr (small -> large) , then calculating DP by sortedArr.
    // O(nlogn)
    let sortedArr = arr.map((v,i)=>([v,i])).sort((a,b)=>a[0]-b[0]);

    // Shifting with single way
    // mid -> left ; mid -> right
    // O(n*d)
    for(let index=1 ; index< n; index++){
        let [v,i] = sortedArr[index];

        for(let shift =1 ; shift <=d ; shift++){
            if(i+shift >= n || arr[i+shift] >= arr[i]) break;
            dp[i] = Math.max(dp[i],dp[i+shift]+1);
            if(dp[i] > result) result = dp[i];
        };

        for(let shift=-1 ; shift >= -d; shift--){
            if(i+shift < 0 || arr[i+shift] >= arr[i]) break;
            dp[i] = Math.max(dp[i],dp[i+shift]+1);
            if(dp[i] > result) result = dp[i];
        };
    };

    return result+1;

};