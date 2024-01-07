// Runtime: 116 ms (Top 100.0%) | Memory: 67.60 MB (Top 61.9%)

var goodDaysToRobBank = function(security, time) {
    let decrease = [0];
    let increase = Array(security.length).fill(0);
    
    // Prefix
    for (let i = 1; i < security.length; i++) {
        if (security[i] <= security[i - 1]) decrease[i] = decrease[i - 1] + 1;
        else decrease[i] = 0;
    }
	
    // Suffix
    for (let j = security.length - 2; j >= 0; j--) {
        if (security[j] <= security[j + 1]) increase[j] = increase[j + 1] + 1;
        else increase[j] = 0;
    }
    
    let output = [];
    for (let k = 0; k < security.length; k++) {
        let left = decrease[k];
        let right = increase[k];
        if (left >= time && right >= time) output.push(k);
    }
    
    return output;
};
