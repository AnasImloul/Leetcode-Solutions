// Runtime: 51 ms (Top 100.00%) | Memory: 43.2 MB (Top 29.03%)
/**
 * @param {string} s
 * @return {boolean}
 */
var splitString = function(s) {

    const backtracking = (index, prevStringValue) => {
        if(index === s.length) {
            return true;
        }
        for(let i = index; i < s.length; i++) {
            const currStringValue = s.slice(index ,i + 1);

            if(parseInt(prevStringValue, 10) === parseInt(currStringValue, 10) + 1) {
                if(backtracking(i + 1, currStringValue)) {
                    return true;
                }
            }
        }
    }
    // we need to have at least two values to compare, so we start with the for outside the backtracking function
    for (let i = 1; i <= s.length - 1; i++) {
        const currStringValue = s.slice(0, i);
        if (backtracking(i, currStringValue)) {
            return true;
        }
    }
    return false
};