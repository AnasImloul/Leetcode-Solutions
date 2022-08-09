var isRationalEqual = function(s, t) {
    return calculate(s) === calculate(t);

    function calculate(v) {
        let start = v.split('(')[0] || v;
        let newer = v.split('(')[1] && v.split('(')[1].split(')')[0] || '0';

        start = start.includes('.') ? start : start + '.';
        newer = newer.padEnd(100, newer);

        return parseFloat(start + newer);
    }
};
