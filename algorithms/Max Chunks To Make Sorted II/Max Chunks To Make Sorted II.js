var maxChunksToSorted = function(arr) {
    var rmin = new Array(arr.length).fill(0);
    rmin[arr.length] = Number.MAX_SAFE_INTEGER;
    
    for(var i=arr.length-1; i>=0; i--) {
        rmin[i] = Math.min(arr[i], rmin[i+1]);
    }
    
    var lmax = Number.MIN_SAFE_INTEGER;
    var count = 0;
    
    for(var i=0; i<arr.length; i++) {
        lmax = Math.max(arr[i], lmax);
        
        if(lmax <= rmin[i+1]) {
            count++;
        }
    }
    
    return count;
};``
