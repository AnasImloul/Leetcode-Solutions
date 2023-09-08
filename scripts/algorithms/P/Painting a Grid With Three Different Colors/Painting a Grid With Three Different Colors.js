// Runtime: 239 ms (Top 77.7%) | Memory: 52.32 MB (Top 22.2%)

// transform any decimal number to its ternary representation
let ternary=(num,len)=>{
    let A=[],times=0
    while(times++<len)
        A.push(num%3),num= (num-num%3)/3
    return A
}
// deduce whether my array does not contain 2 consecutive elements
let adjdiff=Array=>Array.every((d,i)=>i==0||d!==Array[i-1])
//main
var colorTheGrid = function(n, m) {
    let mod=1e9+7,adj=[...Array(3**(n))].map(d=>new Set()),
    //1.turn every potential state to a ternary(base3) representation
        base3=[...Array(3**n)].map((d,i)=>ternary(i,n)),
		//3 conditions such that state a can be previous to state b 
        ok=(a,b)=>adjdiff(base3[a])&& adjdiff(base3[b])&& base3[a].every( (d,i)=>d!==base3[b][i])
    //2.determine what are the acceptable adjacent states of any given state
    for(let m1=0;m1<3**n;m1++)
        for(let m2=0;m2<3**n;m2++)
            if(ok(m1,m2))
                adj[m1].add(m2),adj[m2].add(m1)
    //3.do 2-row dp, where dp[state]= the number of colorings where the last line is colored based on state
    let dp=[...Array(3**n)].map((d,i)=>Number(adjdiff(base3[i])))
    for(let i=1,dp2=[...Array(3**n)].map(d=>0);i<m;i++,dp=[...dp2],dp2.fill(0))
        for(let m1=0;m1<3**n;m1++)
            for(let prev of Array.from(adj[m1]))
                dp2[m1]=(dp2[m1]+dp[prev])%mod
    return dp.reduce((a,c)=> (a+c) %mod ,0)
};