var findRightInterval = function(intervals) {
    const data = intervals
        .map((interval, i) => ({ interval, i }))
        .sort((a, b) => a.interval[0] - b.interval[0]);

    const res = Array(intervals.length).fill(-1);

    for (let pos = 0; pos < data.length; pos++) {
        let left = pos;
        let right = data.length - 1;

        while (left <= right) {
            const mid = Math.floor((left + right) / 2);

            if (data[pos].interval[1] <= data[mid].interval[0]) {
                right = mid - 1;
            } else {
                left = mid + 1;                    
            }
        }

        if (left < data.length) {
            res[data[pos].i] = data[left].i;
        }
    }
    
    return res;
};
