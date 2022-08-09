var maximumRemovals = function(s, p, removable) {
    let arr = s.split('');
    
    const stillFunctions = (k) => {
        let result = [...arr];
        for(let i = 0; i < k; i++) {
            result[removable[i]] = '';
        }

        const isSubset = () => {
            let idx = 0;
            for(let c = 0; c < p.length; c++) {
                if(idx > result.length) return false;
                const next = result.indexOf(p[c], idx);
                if(next === -1) {
                    return false;
                }
                idx = next + 1;
            }
            return true;
        }
        
        return isSubset();
    }

    let left = 0;
    let right = removable.length;
    
    while(left < right) {
        // Need to round up the midpoint since we are returning operation LENGTH i.e. ops+1
        const mid = Math.ceil((left+right) / 2);
        if(!stillFunctions(mid)) {
            right = mid -1;
        } else {
            left = mid;
        }
    }
    return left;
};
