var scoreOfStudents = function(s, answers) {
    let correct=s.split('+').reduce((a,c)=>a+c.split('*').reduce((b,d)=>b*d,1),0),
        n=s.length,dp=[...Array(n)].map(d=>[...Array(n)])
    let dfs=(i=0,j=n-1)=>{
        if(dp[i][j]!==undefined)
            return dp[i][j]
        if(i===j)
            return dp[i][j]=[Number(s[i])]
        let ans=new Set()
        for(let k=i+1;k<=j-1;k+=2)
            for(let a1 of dfs(i,k-1))
                for(let a2 of dfs(k+1,j))
                    if(s[k]==='*')
                        ans.add(Number(a1)*Number(a2))
                    else
                        ans.add(Number(a1)+Number(a2))
        return dp[i][j]=Array.from(ans).filter(d=>d<=1000)
    }
    dfs()
    dp[0][n-1]=new Set(dp[0][n-1])
    return answers.reduce( (a,c)=> a+ (c===correct?5:(dp[0][n-1].has(c)?2:0)) ,0)
};
