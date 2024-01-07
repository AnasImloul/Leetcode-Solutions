// Runtime: 227 ms (Top 66.67%) | Memory: 87.60 MB (Top 53.33%)

/**
 * @param {number} row
 * @param {number} col
 * @param {number[][]} cells
 * @return {number}
 */
var latestDayToCross = function(row, col, cells) {
    //Create empty ground
    const emptyArr = () =>Array(row).fill(0).map(el=>Array(col).fill(0))    
    let ground;

    // Check if path exists
    function isExistPath(){
        //Depth First Search
        function dfs(i,j){
            if(i===row || j === col || j<0 || i<0) return false
            if(ground[i][j]===1) return false
            if(i===row-1) return true
            ground[i][j] = 1
            return dfs(i+1,j) ||dfs(i,j-1) || dfs(i,j+1) || dfs(i-1,j)
        }
        for(let j=0;j<col;j++) if(dfs(0,j)) return true
        return false
    }

    //fill the ground and check paths
    function isGoodGround(end){
        ground = emptyArr()
        for(let i=0; i<=end; i++) ground[cells[i][0]-1][cells[i][1]-1] = 1
        return isExistPath()
    }

    //binary search by day
   let l = -1, r = cells.length
   while(r-l>1){
       const mid = (l+r)>>>1
       if(isGoodGround(mid)) l = mid
       else r = mid
   }
   return l+1;
};
