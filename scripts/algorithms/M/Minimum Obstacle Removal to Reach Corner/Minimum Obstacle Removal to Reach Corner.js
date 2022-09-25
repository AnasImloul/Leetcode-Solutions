// Runtime: 1576 ms (Top 35.29%) | Memory: 109.4 MB (Top 35.29%)
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumObstacles = function(grid) {
    let dx=[[0,1],[0,-1],[1,0],[-1,0]];
    let distance=[];
    for(let i=0;i<grid.length;i++){
        distance[i]=[];
        for(let j=0;j<grid[i].length;j++){
            distance[i][j]=Number.MAX_SAFE_INTEGER;
        }
    }
    return bfs(0,0);

    function bfs(row,col){
        let queue=[];
        distance[row][col]=0;
        queue.push([row,col]);
        while(queue.length>0){
            let element = queue.shift();
            let row = element[0];
            let col = element[1];
            let originalDist = distance[row][col];
            for(let d=0;d<dx.length;d++){
                let i = row + dx[d][0];
                let j = col + dx[d][1];
                if(i>=0 && i<=grid.length-1 && j>=0 && j<=grid[i].length-1){
                    let dist = originalDist;
                    if(grid[i][j]===1){
                        dist++;
                    }
                    if(distance[i][j]>dist){//Update distance for this neighbour node if the new distance is smaller than the previous distance
                        queue.push([i,j]);
                        distance[i][j]=dist;
                    }

                }
            }
        }
        //return the minimum distance for last cell after completing the process
        return distance[(grid.length-1)][(grid[row].length-1)];
    }
};