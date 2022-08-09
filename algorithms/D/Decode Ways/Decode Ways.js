var numDecodings = function(s) {
    let dp = Array(s.length).fill(0); // dp[i] means, the total ways of decode for substring up to i
    dp[0] = (s[0] !== '0') ? 1 : 0;
    
    for(let i = 1; i < s.length; i++){
	//case1
        if(s[i] !== '0'){
            dp[i] = dp[i - 1];
        }
   //case2
        if(s[i-1] === '1' || (s[i-1] === '2' && parseInt(s[i]) <= 6)){
            dp[i] += dp[i - 2] ?? 1;
        }
    }
    
    return dp[s.length - 1];
};
