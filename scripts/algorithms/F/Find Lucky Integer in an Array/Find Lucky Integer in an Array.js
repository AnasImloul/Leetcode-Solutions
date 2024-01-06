// Runtime: 47 ms (Top 95.84%) | Memory: 44.00 MB (Top 53.55%)

// time O(n) space O(n)
var findLucky = function(arr) {
    let max = -1
    
    const map = {}
    
    for(const number of arr) {
        if(map[number]) {
            map[number] += 1
        } else {
            map[number] = 1
        }
    }
    
    for(const key in map) {
        if(Number(key) === map[key] && map[key] > max) {
            max = map[key]
        }
    }
    
    return max
};
