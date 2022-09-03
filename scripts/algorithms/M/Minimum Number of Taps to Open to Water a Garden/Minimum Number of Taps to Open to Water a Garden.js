// Runtime: 150 ms (Top 11.76%) | Memory: 49.1 MB (Top 5.88%)
var minTaps = function(n, ranges) {
    let intervals = [];
    for (let i = 0; i < ranges.length; i++) {
        let l = i - ranges[i];
        let r = i + ranges[i];
        intervals.push([l, r]);
    }

    intervals.sort((a, b) => {
        if (a[0] === b[0]) return b[1] - a[1];
        return a[0] - b[0];
    })

    // Find the starting idx
    let startIdx;
    for (let i = 0; i < intervals.length; i++) {
        let [s, e] = intervals[i];
        if (s <= 0) {
            if (startIdx === undefined) startIdx = i;
            else if (intervals[startIdx][1] < e) startIdx = i;
        } else break;
    }
    if (startIdx === undefined) return -1;

    let q = [startIdx], openedTaps = 1;
    while (q.length) {
        let max;
        while (q.length) {
            let idx = q.pop();
            let [start, end] = intervals[idx];
            if (end >= n) return openedTaps;
            for (let i = idx + 1; i < intervals.length; i++) {
                let [nextStart, nextEnd] = intervals[i];
                // If next interval's start is less than the current interval's end
                if (nextStart <= end) {
                    if (!max && nextEnd > end) max = {i, end: nextEnd};
                    // If the next interval's end is greater than the current interval's end
                    else if (max && nextEnd > max.end) max = {i, end: nextEnd};
                }
                else break;
            }
        }
        if (max) {
            q.push(max.i);
            openedTaps++;
        }
    }

    return -1;
};