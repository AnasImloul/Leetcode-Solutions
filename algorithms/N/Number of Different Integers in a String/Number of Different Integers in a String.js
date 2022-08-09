const CC0 = '0'.charCodeAt(0);

var numDifferentIntegers = function(word) {
    const numStrSet = new Set();
    
    // get numbers as strings
    const numStrs = word.split(/[^0-9]+/);
    
    // drop leading zeros
    for (const numStr of numStrs) {
        if (numStr.length > 0) {
            let i = 0;
            while (numStr.charCodeAt(i) === CC0) i++;
            
            // make sure that we preserve last 0 if string is composed of zeros only
            numStrSet.add(numStr.slice(i) || '0');
        }
    }
    
    return numStrSet.size;
};
