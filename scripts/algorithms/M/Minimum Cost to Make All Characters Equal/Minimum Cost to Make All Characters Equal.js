// Runtime: 78 ms (Top 85.71%) | Memory: 46.20 MB (Top 71.43%)

var minimumCost = function(s) {

    let n = s.length;
    let totalCost = 0;
    for( let i = 0 ; i < n-1 ; i++){
        if( s[i] != s[i+1] ){
            let invertLeft = i+1;    // Invert s[0] to s[i] inclusively
            let invertRight = n-i-1; // Invert s[i+1] to s[n-1] inclusively
                                    // Comes from (n-1) - (i+1) + 1 = n-i-1

            totalCost += Math.min(invertLeft, invertRight);
        }
    }
    return totalCost;

};
