var daysBetweenDates = function(date1, date2) {
     let miliSecondInaDay = 24*60*60*1000;
     if(date1>date2) return (new Date(date1) - new Date(date2)) / miliSecondInaDay
     else return (new Date(date2) - new Date(date1)) / miliSecondInaDay
};
