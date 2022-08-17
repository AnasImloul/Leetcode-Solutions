var longestWPI = function(hours) {
    var dp = new Array(hours.length).fill(0);
    for(i=0;i<hours.length;i++){
       if(dp[i-1]>0 && hours[i]<=8){
            dp[i]=dp[i-1]-1;
            continue;
        }
        let tiring = 0;
        for(j=i;j<hours.length;j++){
            if(hours[j]>8) tiring++;
            else tiring--;
            if(tiring>0) dp[i] = Math.max(dp[i], j-i+1);
        }}
    return Math.max(...dp);
};
