var numSubmatrixSumTarget = function(matrix, target) {
    let result = 0;
    
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 1; j < matrix[0].length; j++) {
            matrix[i][j] = matrix[i][j] + matrix[i][j-1]
        }
    }
    
    for (let i = 0; i < matrix[0].length; i++) {
        for (let j = i; j < matrix[0].length; j++) {
            let dict = {};
            let cur = 0;
            dict[0] = 1;
            
            for (let k = 0; k < matrix.length; k++) {
                cur += matrix[k][j] - ((i > 0)?(matrix[k][i - 1]):0);
                result += ((dict[cur - target] == undefined)?0:dict[cur - target]);
                dict[cur] = ((dict[cur] == undefined)?0:dict[cur])+1;
            } 
        }
    }
    
    return result;
};
