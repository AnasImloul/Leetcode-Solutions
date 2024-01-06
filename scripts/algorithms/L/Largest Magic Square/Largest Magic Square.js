// Runtime: 93 ms (Top 50.0%) | Memory: 42.90 MB (Top 100.0%)

var largestMagicSquare = function(grid) {
   const row = grid.length;
   const col = grid[0].length;
   const startSize = row <= col ? row : col;
   for(let s = startSize; s > 1; s--){
       for(let r = 0; r < grid.length - s + 1; r++){
           for(let c = 0; c < grid[0].length - s + 1; c++){
               if(isMagic(grid, r, c, s)){
                   return s;
               }
           }
       }
   }
   return 1;
};

const isMagic = (grid, i, j, size) => {
   let targetSum = 0;
   for(let c = j; c < j + size; c++){
       targetSum += grid[i][c];
   }
   //check rows
   for(let r = i; r < i + size; r++){
       let sum = 0;
       for(let c = j; c < j + size; c++){
           sum += grid[r][c];
       }
       if(targetSum !== sum){
           return false;
       }
   }
   //check cols
   for(let c = j; c < j + size; c++){
       let sum = 0;
       for(let r = i; r < i + size; r++){
           sum += grid[r][c];
       }
       if(targetSum !== sum){
           return false;
       }
   }
   //check diagonals
   let diagSum = 0, antiDiagSum = 0;
   for(let c = 0; c < size; c++){
       diagSum += grid[i + c][j+c];
       antiDiagSum += grid[i + c][j + size - 1 - c];
   }
   if(diagSum !== antiDiagSum || diagSum !== targetSum){
       return false
   }
   return true;
}
