var minimumBuckets = function(street) {
    const n = street.length;
    const chars = street.split("");
    
    let count = 0;
    
    for (let i = 0; i < n; ++i) {
        const char = chars[i];
        
        if (char === "H") {
            if (i > 0 && chars[i - 1] === "B"){
                continue;
            }
            else if (i < n - 1 && chars[i + 1] === ".") {
                ++count;
                chars[i + 1] = "B";
            }
            else if (i > 0 && chars[i - 1] === ".") {
                ++count;
                chars[i - 1] = "B";
            }
            else {
                return -1;
            } 
        }
    }    
    
    return count;
};
