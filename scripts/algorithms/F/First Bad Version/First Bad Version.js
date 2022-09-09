// Runtime: 109 ms (Top 17.20%) | Memory: 41.9 MB (Top 54.94%)
/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 * ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        let ceiling = n
        let floor = 1
        let firstBadVersion = -1

        while (floor <= ceiling) {
            const middle = Math.floor((ceiling + floor) / 2)

            if (isBadVersion(middle)) {

                firstBadVersion = middle
                ceiling = middle - 1
            } else {
                floor = middle + 1
            }
        }

        return firstBadVersion
    };
};