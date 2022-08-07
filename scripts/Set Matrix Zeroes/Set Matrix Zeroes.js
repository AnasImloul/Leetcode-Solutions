var setZeroes = function(matrix) {
let rows = new Array(matrix.length).fill(0); //to store the index of rows to be set to 0
let cols = new Array(matrix[0].length).fill(0);//to store the index of columns to be set to 0
for(let i=0; i<matrix.length; i++){
    for(let j=0; j<matrix[i].length; j++){
        if(matrix[i][j]===0){//for zero value both row and column will be set to 0
            rows[i] = 1;
            cols[j] = 1;
        }
    }
}

for(let i=0; i<matrix.length; i++){
    for(let j=0; j<matrix[i].length; j++){
        if(rows[i]===1 || cols[j]===1){//if either row or col val is set, poulate it with 0
            matrix[i][j] = 0;
        }
    }
}
};