var countRoutes = function(locations, start, finish, fuel) {
    const memo = new Array(locations.length+1).fill(0).map(()=>new Array(201).fill(-1));
    
    const dfs = function(cur, f){
        if(f<0) return 0;
        if(memo[cur][f]!=-1) return memo[cur][f];
        let res = (cur==finish);
        for(let i in locations){
            if(i==cur) continue;
            res = (res + dfs(i, f-Math.abs(locations[i]-locations[cur])))%1000000007;
        }
        return memo[cur][f]=res;
    }
    
    return dfs(start, fuel);
};
