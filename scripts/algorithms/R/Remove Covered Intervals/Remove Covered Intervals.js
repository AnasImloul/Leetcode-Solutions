// Runtime: 144 ms (Top 6.56%) | Memory: 44.10 MB (Top 88.52%)

var removeCoveredIntervals = function(intervals) {
    intervals.sort((a, b) => (a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]))
    let count = 0, cur = 0
    for(let interval of intervals){
        if(cur < interval[1]){
            cur = interval[1]
            count++
        }
    }
    return count
};
