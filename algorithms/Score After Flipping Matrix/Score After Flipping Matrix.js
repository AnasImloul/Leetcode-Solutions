var matrixScore = function(grid) {
let flip = (i,rowOrCol) => {// helper function for flipping row and column
    if(rowOrCol){
        for(let idx in grid[i]){
            grid[i][idx] = grid[i][idx]===1 ? 0 : 1;
        }
    }
    else{
        for(let idx in grid){
            grid[idx][i] = grid[idx][i]===1 ? 0 : 1;
        }
    }
}

for(let i=0; i<grid.length; i++){// flip rows only if leftmost bit is 0
    if(grid[i][0]!==1){
        flip(i,true);
    }
}

for(let i=1; i<grid[0].length; i++){//flip column only if the number of 1s is less than 0s, as all bits hold equal values in a column
    let ones = 0;
    for(let j in grid){
        ones += grid[j][i];
    }
    if(ones<grid.length/2) flip(i,false);
}

return grid.reduce((a,b) => a + parseInt(b.join(''),2),0);
};