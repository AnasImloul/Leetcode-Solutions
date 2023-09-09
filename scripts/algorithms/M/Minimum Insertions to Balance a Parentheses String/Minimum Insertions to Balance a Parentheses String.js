// Runtime: 58 ms (Top 100.0%) | Memory: 45.84 MB (Top 50.0%)

var minInsertions = function(s) {
    let rightNeeded = 0;
    let leftNeeded = 0;
    for (const char of s) {
        if (char === "(") {
            if (rightNeeded % 2 === 0) {
                rightNeeded += 2;  
            } else {                
                rightNeeded++;
                leftNeeded++;
            }
        } else {
            rightNeeded--;
            if (rightNeeded === -1 ){
                leftNeeded++;
                rightNeeded = 1;
            }
        }
    }
    return leftNeeded + rightNeeded;
};