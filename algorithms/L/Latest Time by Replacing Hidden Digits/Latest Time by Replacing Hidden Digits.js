var maximumTime = function(time) {
    time = time.split('')
    if (time[0] === "?") time[0] = time[1] > 3 ? "1" : "2"
    if (time[1] === "?") time[1] = time[0] > 1 ? "3" : "9"
    if (time[3] === "?") time[3] = "5"
    if (time[4] === "?") time[4] = "9"
    return time.join('')
};
