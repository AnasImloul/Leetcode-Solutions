var numberOfRounds = function(loginTime, logoutTime) {
    const start = toMins(loginTime);
    const end = toMins(logoutTime);

    let roundStart = Math.ceil(start / 15);
    let roundEnd = Math.floor(end / 15);

    if (start < end) {
        return Math.max(0, roundEnd - roundStart); 
    } 
    else {
        roundEnd += 96;
        return roundEnd - roundStart;
    }


    function toMins(timeStr) {
        const [hh, mm] = timeStr.split(":");

        let totMins = 0;

        totMins += parseInt(hh) * 60;
        totMins += parseInt(mm);

        return totMins;
    }
};
