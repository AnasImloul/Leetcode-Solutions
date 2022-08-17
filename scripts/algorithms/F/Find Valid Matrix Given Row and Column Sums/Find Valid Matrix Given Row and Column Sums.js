var restoreMatrix = function(rowSum, colSum) {
    let matrix = new Array(rowSum.length);
    for(let i = 0; i < matrix.length; i++){
        matrix[i] = new Array(colSum.length).fill(0);
    }
let helper = function(row, col, mat) {
        let rowmin = Math.min(...row);   
        let colmin = Math.min(...col);
        let i = col.indexOf(colmin);
        let j = row.indexOf(rowmin);
        if(rowmin === Infinity || colmin === Infinity) return 0;  
        if(rowmin<colmin){
            mat[j][i] = rowmin;
            col[i] -= row[j]; 
            row[j] = Infinity;
        }else{
            mat[j][i] = colmin;
            row[j] -= col[i]; 
            col[i] = Infinity;
            
    }
    
       return helper(rowSum, colSum, matrix);
};
    
    
    helper(rowSum, colSum, matrix);

    

    return matrix;
};
