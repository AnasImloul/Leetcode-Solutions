var decode = function(encoded, first) {
    return [first].concat(encoded).map((x,i,a)=>{return i===0? x : a[i] ^= a[i-1]});
};
