// Runtime: 167 ms (Top 96.67%) | Memory: 72.6 MB (Top 50.00%)
var mergeTriplets = function(triplets, target) {

    let fst = false, snd = false, thrd = false;

    const [t1, t2, t3] = target;

    for(let i = 0; i < triplets.length; i++) {

        const [a, b, c] = triplets[i];

        if(a === t1 && b <= t2 && c <= t3) fst = true;

        if(b === t2 && a <= t1 && c <= t3) snd = true;

        if(c === t3 && a <= t1 && b <= t2) thrd = true;

        if(fst && snd && thrd) return true;
    }
    return false;
};