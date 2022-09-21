// Runtime: 101 ms (Top 52.00%) | Memory: 42.3 MB (Top 94.00%)
var numMagicSquaresInside = function(grid) {
    let res = 0;
    for(let i = 0; i < grid.length - 2; i++){
       for(let j = 0; j < grid[0].length - 2; j++){
           //only check 4
           if(grid[i][j]+grid[i][j+1]+grid[i][j+2]==15
           && grid[i][j]+grid[i+1][j]+grid[i+2][j]==15
           && grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]==15
           && grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]==15){
               let set = new Set();
           for(let a = i; a<=i+2; a++){
              for(let b = j; b<=j+2; b++){
                  if(grid[a][b]>=1&&grid[a][b]<=9) set.add(grid[a][b]);
           }}
           if(set.size===9) res++;
       }}}
    return res;
};