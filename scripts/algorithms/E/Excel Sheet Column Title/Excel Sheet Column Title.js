// Runtime: 66 ms (Top 81.19%) | Memory: 41.8 MB (Top 59.65%)
/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function(columnNumber) {
    let ans = "";
    while(columnNumber >0){
        let n = (--columnNumber) % 26;
        columnNumber = Math.floor(columnNumber/ 26);

        // console.log(String.fromCharCode(65+n),)
        ans+=String.fromCharCode(65 + n);

    }
    ans = ans.split("").reverse().join("")
    return ans
};