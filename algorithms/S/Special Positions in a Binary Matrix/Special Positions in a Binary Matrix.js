/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSpecial = function(mat) {
    let specialPostions = [];
    for(let i in mat){
        for(let j in mat[i]){
            if(mat[i][j] == 1 ){
                let horizontalOnes = 0;
                let verticalOnes = 0;
                    
                for(let k in mat[i]){
                    if(k != j &&  mat[i][k] == 1){
                        horizontalOnes++;
                    }
                }
                    
                for(let k = 0 ; k < mat.length ; k++ ){
                    if(k != i && mat[k][j] == 1){
                        verticalOnes++;
                    }
                }
                    
                if(horizontalOnes == 0 && verticalOnes == 0){
                    specialPostions.push([i,j]);
                }
                
            }
        }
    }
    
    return specialPostions.length;
    
};
