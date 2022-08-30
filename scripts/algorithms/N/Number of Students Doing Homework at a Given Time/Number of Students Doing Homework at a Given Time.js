// Runtime: 83 ms (Top 59.55%) | Memory: 41.9 MB (Top 67.73%)
var busyStudent = function(startTime, endTime, queryTime) {
    let res = 0;

    for (let i = 0; i < startTime.length; i++) {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime) res++;
    }

    return res;
};