var longestSubsequence = function(arr, difference) {
    const map = new Map()
    let max = 0
    for(let num of arr) {
        const prev = map.has(num - difference) ? map.get(num -difference) : 0
        const val = prev + 1
        map.set(num, val)
        max = Math.max(max, val)
    }
    return max
};
