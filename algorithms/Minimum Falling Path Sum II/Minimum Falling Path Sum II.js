var minFallingPathSum = function(grid) {
if(grid.length===1){
    return grid[0][0];
}
let sums = [];//find first, second and third minimum values in the grid as these are only possible values for path
//store the index for fast lookup in a 3D array
for(let i=0; i<grid.length; i++){
    let min = Math.min(...grid[i]);
    let idx = grid[i].indexOf(min);
    grid[i].splice(idx, 1, Infinity);
    let min2 = Math.min(...grid[i]);
    let idx2 = grid[i].indexOf(min2);
    grid[i].splice(idx2, 1, Infinity);
    let min3 = Math.min(...grid[i]);
    let idx3 = grid[i].indexOf(min3);
    sums.push([[min,idx],[min2,idx2],[min3,idx3]]);
}
// sums contains 1st , 2nd and 3rd min value and index
let memo = {}; // for memoization
let recur = (r,li) => {//recursive call to decide which path to choose from r=row, li=lastIndex
    if(memo[r+','+li] !== undefined){// memoized
        return memo[r+','+li];
    }
    if(r===grid.length-1){// last and first choice for path can only be from 1st and 2nd minimum, as there is only one other row to occupy these columns
        if(li===sums[r][0][1]){
            memo[r+','+li] = sums[r][1][0];
        }
        else{
            memo[r+','+li] = sums[r][0][0];
        }
        return memo[r+','+li];
    }
    else{
        switch (li) {// pick the minimum value path where index is not equal to last index
            case sums[r][0][1]:
                memo[r+','+li] = Math.min(sums[r][1][0]+recur(r+1,sums[r][1][1]),sums[r][2][0]+recur(r+1,sums[r][2][1]));
                break;
            case sums[r][1][1]:
                memo[r+','+li] = Math.min(sums[r][0][0]+recur(r+1,sums[r][0][1]),sums[r][2][0]+recur(r+1,sums[r][2][1]));
                break;
            case sums[r][2][1]:
                memo[r+','+li] = Math.min(sums[r][1][0]+recur(r+1,sums[r][1][1]),sums[r][0][0]+recur(r+1,sums[r][0][1]));
                break;
            default:
                memo[r+','+li] = Math.min(sums[r][0][0]+recur(r+1,sums[r][0][1]),sums[r][1][0]+recur(r+1,sums[r][1][1]),sums[r][2][0]+recur(r+1,sums[r][2][1]));
        }
        return memo[r+','+li];
    }
}
return recur(0,sums[0][2][1]);//since first and last can only be picked from 1st and 2nd min values
};