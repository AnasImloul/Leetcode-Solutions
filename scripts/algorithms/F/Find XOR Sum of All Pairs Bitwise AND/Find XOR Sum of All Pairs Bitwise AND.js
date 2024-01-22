// Runtime: 71 ms (Top 88.89%) | Memory: 59.70 MB (Top 11.11%)

var getXORSum = function(arr1, arr2) {
    // (x & 2) xor (x & 3) =[ !(x&2) & (x&3) ] OR  [ (x&2) & !(x&3) ]
	// = [ (!x || !2 ) & (x&3) ] OR [ (x&2) & (!x || !3) ]
    // = [ (!x || !2) & x & 3 ]   OR  [ x & 2 & (!x || !3) ]
    // = (!2 & x & 3 ) || (x & 2 & !3)
    // = x & [ (!2 & 3) || (!3 & 2) ]
    // = x & (2 XOR 3)
    // const ans = (2 XOR 3 XOR....) in arr2
    // The same principle: x, y,z... in arr1
    // res = (x & ans) XOR (y & ans) XOR .....
    //  = ans & (x XOR y XOR z .......)
    // Finally: res = (XOR: arr1) AND (XOR: arr2);
    var xor1 = arr1.reduce((acc,cur)=>acc^cur);
    var xor2 = arr2.reduce((acc,cur)=>acc^cur);
    return xor1 & xor2;
};
