var addRungs = function(rungs, dist) {
    let res = 0;
    let prev = 0;
    for ( let i = 0; i < rungs.length; i++ ){
        res += Math.floor(( rungs[i] - prev - 1 ) / dist ); 
        prev = rungs[i];
    }
    return res;
};

