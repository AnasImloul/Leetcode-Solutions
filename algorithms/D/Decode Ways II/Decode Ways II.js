var numDecodings = function(s) {
    let len = s.length;
    if(len === 0) return s;
    let mod = Math.pow(10,9)+7;
    let dp = new Array(len+1).fill(0);
    dp[0] = 1;
    if(s[0] == 0) dp[1] = 0;
    else if(s[0] == '*') dp[1] = 9;
    else dp[1] = 1;
    for(let i=2;i<=len;i++){
        if(s[i-1] == '*'){
            dp[i] += 9*dp[i-1];
        } else if(s[i-1] != 0 && s[i-1] != '*'){
            dp[i] += dp[i-1]; 
        }
        if(s[i-2] == 1){
            if(s[i-1] == '*') dp[i] += 9*dp[i-2];
            else dp[i] += dp[i-2];
        } else if(s[i-2] == 2){
            if(s[i-1]<7) dp[i] += dp[i-2];
            else if(s[i-1] == '*') dp[i] += 6*dp[i-2];            
        } else if(s[i-2] == '*'){
            if(s[i-1] == '*') dp[i] += 15*dp[i-2];
            else if(s[i-1]>=0 && s[i-1]<=6) dp[i] += 2*dp[i-2];
            else if(s[i-1] >=7) dp[i] += dp[i-2];
        }
        dp[i] = dp[i]%mod;
    }
    return dp[len]%mod;
};
