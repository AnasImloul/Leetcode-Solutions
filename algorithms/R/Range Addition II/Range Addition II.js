var maxCount = function(m, n, ops) {
    if( ops.length === 0 )
        return m*n
    let min_a = m , min_b = n
    for( let [x,y] of ops ){
        if( x < min_a )
            min_a = x
        if( y < min_b )
            min_b = y
    }
    return min_a * min_b
};
