/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    const n = s.length;
    const CHAR_CODE_UPPER_E = 'E'.charCodeAt(0);
    const CHAR_CODE_LOWER_E = 'e'.charCodeAt(0);
    const CHAR_CODE_UPPER_A = 'A'.charCodeAt(0);
    const CHAR_CODE_UPPER_Z = 'Z'.charCodeAt(0);
    const CHAR_CODE_LOWER_A = 'a'.charCodeAt(0);
    const CHAR_CODE_LOWER_Z = 'z'.charCodeAt(0);

    let sign = '';
    let decimal = '';
    let exponential = '';
    let exponentialSign = '';
    let num = '';
    for(let i = 0; i < n; i += 1) {
        const char = s[i];
        const charCode = s.charCodeAt(i);

        if(char === '+' || char === '-') {
            if(i === n - 1) return false;
            if(i === 0) {
                sign = char;
                continue;
            }

            if(exponentialSign.length > 0) return false;
            if(!(s[i - 1] === 'e' || s[i - 1] === 'E')) return false;
            exponentialSign = char;
            continue;
        }

        if(char === '.') {
            if(decimal.length > 0) return false;
            if(exponential.length > 0) return false;
            if(num.length === 0 && i === n - 1) return false;

            decimal = char;
            continue;
        }

        if(charCode === CHAR_CODE_UPPER_E || charCode === CHAR_CODE_LOWER_E) {
            if(exponential.length > 0) return false;
            if(i === n - 1) return false;
            if(num.length === 0) return false;

            exponential = char;
            continue;
        }

        if(charCode >= CHAR_CODE_UPPER_A && charCode <= CHAR_CODE_UPPER_Z) {
            return false;
        }

        if(charCode >= CHAR_CODE_LOWER_A && charCode <= CHAR_CODE_LOWER_Z) {
            return false;
        }

        num += char;
    }

    return true;
};
