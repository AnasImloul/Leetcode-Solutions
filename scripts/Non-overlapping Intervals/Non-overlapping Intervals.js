var eraseOverlapIntervals = function(intervals) {
    // sort by end's small to big
    intervals.sort((a, b) => a[1] - b[1]);
    
    let total = 1;
    let maxEnd = intervals[0][1];
    
    for (let i = 1; i < intervals.length; i++) {
        let [start, end] = intervals[i];
        if (start >= maxEnd) {
            total++;
            maxEnd = end
        }
    }
    
    return intervals.length - total;
};
