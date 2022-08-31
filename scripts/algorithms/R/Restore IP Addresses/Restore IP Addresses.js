// Runtime: 105 ms (Top 48.16%) | Memory: 44.6 MB (Top 28.44%)
var restoreIpAddresses = function(s) {
    const results = [];

    const go = (str, arr) => {
        // if we used every character and have 4 sections, it's a good IP!
        if (str.length === 0 && arr.length === 4) {
            results.push(arr.join('.'));
            return;
        }
        // we already have too many in the array, let's just stop
        if (arr.length >= 4) {
            return;
        }
        // chop off next 3 characters and continue recursing
        if (str.length > 2 && +str.substring(0, 3) < 256 && +str.substring(0, 3) > 0 && str[0] !== '0') {
            go(str.slice(3), [...arr, str.substring(0, 3)]);
        }
        // chop off next 2 characters and continue recursing
        if (str.length > 1 && +str.substring(0, 2) > 0 && str[0] !== '0') {
            go(str.slice(2), [...arr, str.substring(0, 2)]);
        }
        // chop off next 1 character and continue recursing, in this case, starting with 0 is OK
        if (str.length > 0 && +str.substring(0, 1) >= 0) {
            go(str.slice(1), [...arr, str.substring(0, 1)]);
        }
        return;
    }

    go(s, []);

    return results;
};