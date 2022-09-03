// Runtime: 85 ms (Top 82.20%) | Memory: 46.8 MB (Top 16.95%)
var shortestPalindrome = function(s) {
    const rev = s.split('').reverse().join('');
    const slen = s.length;

    const z = s + '$' + rev;
    const zlen = z.length;

    const lpt = new Array(zlen).fill(0);

    for(let i = 1; i < zlen; i++) {
        let j = lpt[i-1];

        while(j > 0 && z.charAt(i) != z.charAt(j))
            j = lpt[j-1];

        if(z.charAt(i) == z.charAt(j))
            j++;

        lpt[i] = j;
    }

    return rev.slice(0, slen - lpt.at(-1)) + s;
};