var predictPartyVictory = function(senate) {
    let index = 0, RCount = 0, DCount = 0, deletion = false, delCount = 1;
    while(delCount || index < senate.length) {
        if(index >= senate.length) {
            index = 0;
            delCount = 0;
        }
        deletion = false;
        if(senate.charAt(index) == 'R') {
            if(DCount > 0) {
                senate = senate.slice(0,index)+senate.slice(index+1);
                DCount--;
                index--;
                deletion = true;
                delCount++;
            }
            else {
                RCount++;
            }
        }
        else if(senate.charAt(index) == 'D') {
            if(RCount > 0) {
                senate = senate.slice(0,index)+senate.slice(index+1);
                RCount--;
                index--;
                deletion = true;
                delCount++;
            }
            else {
                DCount++;
            }
        }
        if(index == senate.length-1) {
            if(senate.charAt(0) == 'R' && senate.charAt(index) == 'D' && DCount > 0 && !deletion) {
                senate = senate.slice(1);
                DCount--;
                index = -1;
            }
            else if(senate.charAt(0) == 'D' && senate.charAt(index) == 'R' && RCount > 0 && !deletion) {
                senate = senate.slice(1);
                RCount--;
                index = -1;
            }            
        }
        index++;
    }
    return senate.charAt(0) == 'D' ? 'Dire' : 'Radiant';
};
