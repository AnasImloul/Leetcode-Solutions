/**
 * find all bit switches '01' and '10'. 
 * From each one expand sideways: i goes left, j goes right
 * Until:
 * if '01' -> i,j != 0,1
 * if '10' -> i,j != 1,0
 * and within input boundaries
 */
var countBinarySubstrings = function(s) {
    let i = 0;
    const n = s.length;
    let count = 0;
    while (i < n-1) {
        if (s[i] != s[i+1]) {
            if (s[i] === '0') {
                count += countZeroOnes(s, i, true);
            } else {
                count += countZeroOnes(s, i, false);
            }
            
        }
        i++;
    }
    return count;
    
    // count the number of valid substrings substrings
    function countZeroOnes(s, start, startsWithZero) {
        let count = 0;
        let i = start;
        let j = start+1;
        const n = s.length;
        if (startsWithZero) {
            while(i >= 0 && j < n && s[i] === '0' && s[j] === '1') {
                count++;
                i--;
                j++;
            }
        } else {
            while(i >= 0 && j < n && s[i] === '1' && s[j] === '0') {
                count++;
                i--;
                j++;
            }
        }
        return count;
    }
}
