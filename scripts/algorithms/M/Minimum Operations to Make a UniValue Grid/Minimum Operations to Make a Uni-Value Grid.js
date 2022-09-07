// Runtime: 281 ms (Top 100.00%) | Memory: 71.2 MB (Top 40.00%)
var minOperations = function(grid, x) {

    let remainder = -Infinity, flatten = [], res = 0;

    for(let i = 0;i<grid.length;i++){
        for(let j = 0;j<grid[i].length;j++){

            if(remainder === -Infinity)
                remainder = grid[i][j] % x;
            else if(remainder !== grid[i][j] % x){
                return -1;
            }
            flatten.push(grid[i][j])
        }
    }
    flatten.sort((a,b)=> a-b);
    let median = flatten[~~(flatten.length/2)]

    for(let i = 0;i<flatten.length;i++){
        res += Math.abs(flatten[i] - median) / x
    }
    return res;
};