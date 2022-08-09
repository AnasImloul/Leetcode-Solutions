var processQueries = function(queries, m) {
    let result = [];
    let permutation = [];
    for(let i=0; i<m; i++){
        permutation.push(i+1);
    }
    
    for(let i=0; i<queries.length; i++){
        let index = permutation.indexOf(queries[i]);
        result.push(index);
        permutation.splice(index,1);
        permutation.unshift(queries[i]);
    }
    return result;
};