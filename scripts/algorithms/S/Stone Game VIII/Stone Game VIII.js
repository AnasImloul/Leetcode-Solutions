// Runtime: 186 ms (Top 100.0%) | Memory: 63.30 MB (Top 50.0%)

var stoneGameVIII = function(S) {  
    let n=S.length, prefix=[0],dp=[...Array(n)]
    for(let i=0;i<n;i++)
        prefix.push(prefix[prefix.length-1]+S[i])
    let bestRight=prefix[n],bestCurrent
    for(let i=n-2;i>=0;i--)
        bestCurrent=bestRight,
		//update what you re going to use in the future
        bestRight=Math.max(bestRight,prefix[i+1]-bestCurrent) 
    return bestCurrent
};
