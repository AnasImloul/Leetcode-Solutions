var busyStudent = function(startTime, endTime, queryTime) {
    let res = 0;
    
    for (let i = 0; i < startTime.length; i++) {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime) res++;
    }
    
    return res;
};
