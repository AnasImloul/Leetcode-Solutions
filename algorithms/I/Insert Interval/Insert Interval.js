var insert = function(intervals, newInterval) {
    //Edge case
    if (intervals.length === 0) {
        return [newInterval];
    }
	//Find the index to insert newIntervals
    let current = 0;
    while (current < intervals.length && intervals[current][0] < newInterval[0]) {
        current++;
    }
    intervals.splice(current, 0, newInterval);
	//If newInterval is not the last index, check the element behigh newInterval to see if merge is needed
    if (current !== intervals.length -1) {
        let pointer = current + 1;
        if (intervals[pointer][0] <= newInterval[1]) {
            while (pointer < intervals.length && intervals[pointer][0] <= newInterval[1]) {
                pointer++;
            }
            newInterval[1] = Math.max(newInterval[1], intervals[pointer - 1][1]);
            intervals.splice(current + 1, pointer - (current + 1));
        }
    }
	//If newInterval is not the first index, check the element berfore newInterval to see if merge is needed
    if (current !== 0) {
        if (intervals[current - 1][1] >= newInterval[0]) {
            newInterval[0] = intervals[current - 1][0];
            newInterval[1] = Math.max(newInterval[1], intervals[current - 1][1]);
            intervals.splice(current - 1, 1);
        }
    }
    return intervals;
};
