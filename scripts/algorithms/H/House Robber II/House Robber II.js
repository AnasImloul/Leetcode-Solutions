// Runtime: 81 ms (Top 62.79%) | Memory: 42.1 MB (Top 52.33%)
var rob = function(nums) {

    let dp = []
    dp[0] = [0,0]
    dp[1] = [nums[0],0]

    for(let i=2; i<=nums.length;i++){
        let val = nums[i-1]

        let rob = dp[i-2][0] + val
        let dont = dp[i-1][0]
        let noFirst = dp[i-2][1] + val

        let best = (rob>=dont)?rob:dont

        if(dp[i-1][1]>noFirst) noFirst=dp[i-1][1]

        if(i!=nums.length){
            dp[i] = [best,noFirst]
        }else{
            dp[i] = [dont,noFirst]
        }

    }
    return (dp[nums.length][0]>=dp[nums.length][1]) ? dp[nums.length][0]:dp[nums.length][1]

};