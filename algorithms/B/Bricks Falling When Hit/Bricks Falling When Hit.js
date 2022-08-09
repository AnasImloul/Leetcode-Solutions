
 var hitBricks = function(grid, hits) {
    let output = []
    for (let i = 0; i < hits.length; i++) {
        let map = {};
        
        if (grid[hits[i][0]][hits[i][1]] == 1) {
            
            grid[hits[i][0]][hits[i][1]] = 0;
            
            
            for (let j = 0; j<grid[0].length; j++) {
                if (grid[0][j] == 1) {
                    dfs (grid, output, map, 0, j);
                    break;
                }
            }
            /* removing bricks that are not connected and adding the count to array */
            removeBricks(grid, map, output);  
        } else {
            output.push(0)
        }
        
        
    }
    return output;
};

function dfs(grid, output, map, i, j) {
    
    if (i >= grid.length || j >= grid[0].length || i < 0 || j < 0) return;
    
    let key = i +'_'+ j
    
    if (map[key]) return;
    
    if (grid[i][j] == 1) {
        
        map[key] = 1;
        
        dfs(grid, output, map, i+1, j);
        dfs(grid, output, map, i-1, j);
        dfs(grid, output, map, i, j+1);
        dfs(grid, output, map, i, j-1);
        
    }
    
}

function removeBricks (grid, map, output) {
    let count = 0;
    for (let row = 0; row < grid.length; row++) {
        for (let col = 0; col < grid[row].length; col++) {
            let key = row +'_'+ col;
            
            if (grid[row][col] == 1 && !map[key] ) {
                grid[row][col] = 0;
                count++
            }
        }
    }
    output.push(count)
    
}

