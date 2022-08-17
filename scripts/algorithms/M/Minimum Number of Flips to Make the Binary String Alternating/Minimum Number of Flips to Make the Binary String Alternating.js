/*

startZeroNumFlips:  number of flips if string were to start at i and start with 0
startOneNumFlips:  number of flips if string were to start at i and start with 1

*/
 var minFlips = function(s) {
    // value to hold starting with zero
    let startZeroNumFlips = 0;
    for (let i = 0; i < s.length; i++) {
        if (i % 2) {
            if (s[i] === '0') startZeroNumFlips++;
        } else {
            if (s[i] === '1') startZeroNumFlips++;
        }
    }
    let startOneNumFlips = s.length - startZeroNumFlips;

    let minimumFlips = Math.min(startZeroNumFlips, startOneNumFlips);
    const isEvenLength = s.length % 2 === 0;

    for (let i = 1; i < s.length; i++) {
        
        // check the previous char to see which
        // value to decrement
        if (s[i - 1] === '1') {
            startZeroNumFlips--;    
        } else {
            startOneNumFlips--;
        }

        // swap the 2 variables because we shifted the index by 1
        [startOneNumFlips, startZeroNumFlips] = [startZeroNumFlips, startOneNumFlips];

        // add corresponding number of flips
        if (isEvenLength) {
            if (s[i - 1] === '1') {
                startOneNumFlips++;
            } else {
                startZeroNumFlips++;
            }
        } else {
            if (s[i - 1] === '1') {
                startZeroNumFlips++;
            } else {
                startOneNumFlips++;
            }
        }

        // calculate the number of flips
        minimumFlips = Math.min(startZeroNumFlips, startOneNumFlips, minimumFlips);
    }
    return minimumFlips;
};
