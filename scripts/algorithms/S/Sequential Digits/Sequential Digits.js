// Runtime: 50 ms (Top 82.3%) | Memory: 42.65 MB (Top 5.8%)

var sequentialDigits = function(low, high) {
    const digits = '123456789';
    const ans = [];
    
    const minLen = low.toString().length;
    const maxLen = high.toString().length;
    
    for (let windowSize = minLen; windowSize <= maxLen; ++windowSize) {
        for (let i = 0; i + windowSize <= digits.length; ++i) {
            const num = parseInt(digits.substring(i, i + windowSize));
            
            if (num >= low && num <= high) {
                ans.push(num);
            }
        }
    }
    
    
    return ans;
};