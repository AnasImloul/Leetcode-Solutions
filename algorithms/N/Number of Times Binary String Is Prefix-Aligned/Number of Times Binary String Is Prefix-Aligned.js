var numTimesAllBlue = function(flips) {
    const flipped = new Array(flips.length).fill(0);
    let prefixAlignedCount = 0;
    flips.forEach((i, step) => {
        flipped[i - 1] = 1;
        if(isPrefixAligned(step)) {
            ++prefixAlignedCount;
        }
    })
    return prefixAlignedCount;
    
    function isPrefixAligned(step) {
        for(let i = 0; i < flips.length; ++i) {
            if((i < step && flipped[i] === 0) || (i > step && flipped[i] === 1)) {
                return false;
            }
        }
        return true;
    }
};
