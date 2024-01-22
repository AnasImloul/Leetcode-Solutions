// Runtime: 96 ms (Top 94.12%) | Memory: 59.50 MB (Top 11.76%)

var minPathCost = function(grid, moveCost) {

    const dfs=(r,c,dp)=>{
        if(r===grid.length || c===grid[r].length) return 0;
        if(dp[r][c]!==undefined) return dp[r][c];

        // current cost
        const cost=grid[r][c], nextRow=r+1;

        if(nextRow===grid.length) return cost;
        
        let nextMoveCost=Number.MAX_SAFE_INTEGER;
        for(let nextCol=0;nextCol<grid[nextRow].length;nextCol++){
            nextMoveCost=Math.min(nextMoveCost,dfs(nextRow,nextCol,dp)+moveCost[cost][nextCol]/*path cost*/);
        }
        return dp[r][c]=cost+(nextMoveCost===Number.MAX_SAFE_INTEGER?0:nextMoveCost);
    };

    let minCost=Number.MAX_SAFE_INTEGER;
    const dp=Array(grid.length).fill().map(()=>Array(grid[0].length).fill());
    for(let c=0;c<grid[0].length;c++){
        minCost=Math.min(minCost,dfs(0,c,dp));
    }
    return minCost;
};
