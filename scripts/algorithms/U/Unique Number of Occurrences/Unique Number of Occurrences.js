// Runtime: 54 ms (Top 59.88%) | Memory: 43.70 MB (Top 21.19%)

// time O(n) space O(n)
var uniqueOccurrences = function(arr) {
    const map = {}
    
    for(const number of arr) {
        if(map[number]) {
            map[number] += 1
        } else {
            map[number] = 1
        }
    }
    
    const frequencies = Object.values(map)
    const set = new Set(frequencies)
    
    return frequencies.length === set.size
};
