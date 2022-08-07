var getRow = function(rowIndex) {
    const triangle = [];
    
    for (let i = 0; i <= rowIndex; i++) {
        const rowValue = [];
        
        for (let j = 0; j < i + 1; j++) {
             if (j === 0 || j === i) {
                 rowValue[j] = 1;
             } else {
                 rowValue[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
             }
        }
        triangle.push(rowValue)
    }
    
    return triangle[rowIndex];
};
