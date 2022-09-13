// Runtime: 88 ms (Top 77.00%) | Memory: 44.4 MB (Top 78.92%)

var transpose = function(matrix){
    let result = []
    for(let i=0;i<matrix[0].length;i++){

        let col = []

        for(let j= 0;j<matrix.length;j++){
            col.push(matrix[j][i])
        }
        result.push(col)
    }
    return result
};

    console.log(transpose( [ [1 , 2 , 3] , [ 4 , 5 , 6 ] , [ 7 , 8 , 9 ] ] ) )