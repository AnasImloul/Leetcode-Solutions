// Runtime: 126 ms (Top 74.14%) | Memory: 44.6 MB (Top 82.76%)
/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSubmat = function(mat) {
    var m = mat.length;
    var n = mat[0].length;

    for(let i=0; i<m; i++){
        for(let j = n-2; j>=0; j-- ){
            if(mat[i][j] === 0)continue;
            mat[i][j] += mat[i][j+1];

        }
    }
    var sum = 0
    for(let i=0; i<m; i++){
        for(let j = 0; j<n; j++ ){
            if(mat[i][j] === 0)continue;
            var min = mat[i][j]

            for(let k=i; k<m; k++){
                if(mat[k][j] === 0)break;
                min = Math.min(min , mat[k][j])
                sum += min
            }
        }

    }
    return sum
};