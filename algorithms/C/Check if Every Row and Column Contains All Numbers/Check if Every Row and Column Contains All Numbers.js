var checkValid = function(matrix) {    
    for(let i =0; i<matrix.length;i++){
        const cols = new Set(), rows = new Set(matrix[i]);
		
        for(let j =0; j<matrix.length;j++){
            if(matrix[j][i] > matrix.length) return false;
            cols.add(matrix[j][i])
        }
		
        if(cols.size < matrix.length || rows.size < matrix.length) return false;
    }
    return true;
};

