// Runtime: 61 ms (Top 99.69%) | Memory: 45.4 MB (Top 72.33%)
/**
 * @param {string[]} logs
 * @return {string[]}
 */
var reorderLogFiles = function(logs) {
    const res = [];

    for (i=0; i<logs.length; i++) {
        let curr = logs[i].split(' ');
        if (isNaN(Number(curr[1]))) res.push(logs[i]);
    }

    res.sort((a,b) => {
        let first = a.split(' ');
        let second = b.split(' ');
        let fLetter = first.slice(1).join(' ');
        let sLetter = second.slice(1).join(' ');

        if (fLetter > sLetter) return 1;
        else if (fLetter < sLetter) return -1;
        else {
            if (first[0] >= second[0]) return 1;
            else return -1;
        }

    })

    for (i=0; i<logs.length; i++) {
        let curr = logs[i].split(' ');
        if (!isNaN(Number(curr[1]))) res.push(logs[i]);
    }

    return res;
};