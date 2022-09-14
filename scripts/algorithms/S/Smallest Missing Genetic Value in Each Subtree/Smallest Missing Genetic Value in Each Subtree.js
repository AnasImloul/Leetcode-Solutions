// Runtime: 689 ms (Top 100.00%) | Memory: 160 MB (Top 83.33%)
var smallestMissingValueSubtree = function(parents, nums) {
    let n=parents.length,next=[...Array(n)].map(d=>[]),used={}
    for(let i=1;i<n;i++)
        next[parents[i]].push(i)
    let dfs=(node)=>{
        if(used[nums[node]])
            return
        used[nums[node]]=true
        for(let child of next[node])
            dfs(child)
    }
    let cur=nums.indexOf(1),leftAt=1,res=[...Array(n)].map(d=>1)
    while(cur!==-1){
        dfs(cur)
        while(used[leftAt])
            leftAt++
        res[cur]=leftAt
        cur=parents[cur]
    }
    return res
};