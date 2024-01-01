// Runtime: 55 ms (Top 83.33%) | Memory: 42.20 MB (Top 85.19%)

var surfaceArea = function(grid) {
    let cube=0, overlap=0;
    for(let i=0; i<grid.length; i++){
        for(let j=0; j<grid[i].length; j++){
            cube+=grid[i][j];
            if(i>0){overlap+=Math.min(grid[i][j], grid[i-1][j]);} // x-direction
            if(j>0){overlap+=Math.min(grid[i][j], grid[i][j-1]);} // y-direction
			if(grid[i][j]>1){overlap+=grid[i][j]-1}; // z-direction
        }
    }
    return cube*6-overlap*2;
};
