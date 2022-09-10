// Runtime: 94 ms (Top 40.52%) | Memory: 41.3 MB (Top 100.00%)
var daysBetweenDates = function(date1, date2) {
     let miliSecondInaDay = 24*60*60*1000;
     if(date1>date2) return (new Date(date1) - new Date(date2)) / miliSecondInaDay
     else return (new Date(date2) - new Date(date1)) / miliSecondInaDay
};