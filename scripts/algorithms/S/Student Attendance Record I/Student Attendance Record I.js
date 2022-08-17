var checkRecord = function(s) {
    let absent = 0;
    let lates = 0;
    for (let i = 0; i < s.length; i++) {
        if(s[i] === 'L') {
            lates++;
            if(lates > 2) return false;
        } else {
            lates = 0;
            if(s[i] === 'A') {
                absent++;
                if(absent > 1) return false; 
            }
        }
    }
    return true;
};
