/**
 * @param {string[]} keyName
 * @param {string[]} keyTime
 * @return {string[]}
 */
var alertNames = function(keyName, keyTime) {
    // so we don't keep duplicates
    const abusers = new Set();
    // map: name->times[] (sorted)
    const times = {};
    for (let i=0; i<keyName.length; i++) {
        const name = keyName[i];
        const time = keyTime[i];
        if (times[name] == null) times[name] = [];
        times[name].push(time);
        
        if (times[name].length > 2) {
            times[name].sort();
            const len = times[name].length;
            // we check all triples for a time difference below 1 hour.
            // as times are sorted, we need to check all i and i+2
            for (let i=0; i<len-2; i++) {
                if (belowHour(times[name][i], times[name][i+2])) {    
                    abusers.add(name);
                }
            }
        }
        
    }
    const ar = Array.from(abusers);
    // sort them lexicographically
    ar.sort();
    return ar;
        
    /*
    same hour: true
    hour diff is above 1: false
    hour diff is 1: m2 must be <= m1
    */
    function belowHour(t1, t2) {
        const [h1, m1] = t1.split(':').map(num => parseInt(num));
        const [h2, m2] = t2.split(':').map(num => parseInt(num));
        if (h1 === h2) return true;
        if (h2-h1 > 1) return false;
        if (m2 <= m1) return true;
    }
};
