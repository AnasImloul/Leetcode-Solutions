// Runtime: 125 ms (Top 10.81%) | Memory: 42.4 MB (Top 45.95%)
/**
 * @param {number} a
 * @param {number} b
 * @return {string}
 */
var strWithout3a3b = function(a, b) {
    let r = '';

    let A = 'a', AA = A + A;
    let B = 'b', BB = B + B;

    while (a > 0 || b > 0) {
        if (a > b) {
            a = calculate(a, A, AA);
            b = calculate(b, B, BB, true);
        }
        else {
            b = calculate(b, B, BB);
            a = calculate(a, A, AA, true);
        }
    }

    return r;

    function calculate(v, s, ss, l = false) {
        if (l) {
            if (v > 0) {
                r += s, v -= 1;
            }

            return v;
        }

        let c = v >= 2 && r[r.length - 1] !== s;

        r += c ? ss : s;
        v -= c ? 2 : 1;

        return v;
    }
};