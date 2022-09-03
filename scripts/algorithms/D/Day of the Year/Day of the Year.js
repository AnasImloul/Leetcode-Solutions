// Runtime: 398 ms (Top 16.77%) | Memory: 51.3 MB (Top 62.28%)
var dayOfYear = function(date) {
    let dat2 = new Date(date)
    let dat1 = new Date(dat2.getFullYear(),00,00)
    let totalTime = dat2 - dat1
    return Math.floor(totalTime/1000/60/60/24)
};