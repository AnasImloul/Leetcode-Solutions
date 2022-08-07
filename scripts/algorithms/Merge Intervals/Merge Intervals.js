/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */

var merge = function(intervals) {
    // sorting the intervals array first is a general good first step
    intervals.sort((a,b) => a[0] - b[0]);
    const result = [];
    // i am using the result array as a way to compare previous and next intervals
    result.push(intervals[0])
    for (let i=1; i<intervals.length; i++) {
        const prevInterval = result[result.length-1]
        const interval = intervals[i]
        
        if (prevInterval[1] >= interval[0]) {
            // overlap detected
            const [ l, r ] = result.pop();
            // if overlap, merge intervals by taking min/max of both boundaries
            const newL = Math.min(l, interval[0])
            const newR = Math.max(r, interval[1])
            result.push([newL, newR])
        } else {
            result.push(intervals[i])
        }
    }
    return result
};
