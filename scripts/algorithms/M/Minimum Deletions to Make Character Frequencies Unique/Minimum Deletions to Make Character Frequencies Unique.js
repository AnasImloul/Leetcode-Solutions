// Runtime: 66 ms (Top 94.87%) | Memory: 46.30 MB (Top 91.45%)

var minDeletions = function(s) {
    let freq = new Array(26).fill(0); // Create an array to store character frequencies
    
    for (let i = 0; i < s.length; i++) {
        freq[s.charCodeAt(i) - 'a'.charCodeAt(0)]++; // Count the frequency of each character
    }
    
    freq.sort((a, b) => a - b); // Sort frequencies in ascending order
    
    let del = 0; // Initialize the deletion count
    
    for (let i = 24; i >= 0; i--) {
        if (freq[i] === 0) {
            break; // No more characters with this frequency
        }
        
        if (freq[i] >= freq[i + 1]) {
            let prev = freq[i];
            freq[i] = Math.max(0, freq[i + 1] - 1);
            del += prev - freq[i]; // Update the deletion count
        }
    }
    
    return del; // Return the minimum deletions required
};

