var minSwaps = function(s) {
    let ones = 0;
    let zeroes = 0;
    
    for(let c of s) {
        if(c === "1") ones++
        else zeroes++
    }
    
    if(Math.abs(ones - zeroes) > 1) return -1
    
    function count(i) {
        let res = 0
        for(let c of s) {
            if(i !== c) res++;
            if(i === "1") i = "0";
            else i = "1";
        }
        
        return res/2;
    };
    
    if(ones > zeroes) return count("1")
    if(zeroes > ones) return count("0")

    return Math.min(count("1"), count("0"));
};
