/**
 * @param {number} n
 * @param {number} delay
 * @param {number} forget
 * @return {number}
 */
var peopleAwareOfSecret = function(n, delay, forget) {
    const dp=new Array(n+1).fill(0);
    let numberOfPeopleSharingSecret = 0;
    let totalNumberOfPeopleWithSecret = 0;
    const MOD = 1000000007n;
    
    dp[1]=1; // as on day one only one person knows the secret
    
    for(let i=2;i<=n;i++){
        const numberOfNewPeopleSharingSecret = dp[Math.max(i-delay,0)];
        const numberOfPeopleForgettingSecret = dp[Math.max(i-forget,0)];
        numberOfPeopleSharingSecret = BigInt(numberOfPeopleSharingSecret) + 
            (   BigInt(numberOfNewPeopleSharingSecret) 
              - BigInt(numberOfPeopleForgettingSecret) 
              + BigInt(MOD)
            ) % BigInt(MOD);
        
        dp[i] = numberOfPeopleSharingSecret;
    }
    
    for(let i=n-forget+1;i<=n;i++){
       totalNumberOfPeopleWithSecret = 
           (BigInt(totalNumberOfPeopleWithSecret) + BigInt(dp[i])) % BigInt(MOD); 
    }
    
    return totalNumberOfPeopleWithSecret;
};
