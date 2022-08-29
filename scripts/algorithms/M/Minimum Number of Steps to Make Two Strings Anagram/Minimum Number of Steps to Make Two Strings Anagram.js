// Runtime: 290 ms (Top 23.15%) | Memory: 46.9 MB (Top 83.22%)
var minSteps = function(s, t) {

    let hash1 = hash(s);
    let hash2 = hash(t);
    let steps = 0;

    for(let key of Object.keys(hash1)) {
        if( hash2[key]) {
            hash1[key] = hash1[key] - hash2[key];
        }
        if( hash1[key] > 0 ) {
            steps += hash1[key];
        }
    }

    return steps;
};

function hash(str) {
    let hash = {};
    for(let i=0; i<str.length; i++) {
        let letter = str[i];
        if( hash[letter] ) {
            hash[letter]++;
        } else {
            hash[letter] = 1;
        }
    }

    return hash;
}