// Runtime: 107 ms (Top 57.83%) | Memory: 44.1 MB (Top 42.17%)
/**
 * @param {string} s
 * @param {string[]} words
 * @return {number}
 */
var expressiveWords = function(s, words) {
    let arr = [];
    let curr = 0
    while(curr < s.length){
        let count = 1
        while(s[curr] === s[curr+1]){
            count++;
            curr++
        }
        arr.push([s[curr] , count]);
        curr++
    }
    let ans = 0
    for(let charArr of words){
        let idx = 0;
        let i = 0;
        let flag = true;
        if(charArr.length > s.length)continue

        while( i < charArr.length ){
            let count = 1
            while(charArr[i] === charArr[i+1]){
                i++;
                count++
            }
            if(arr[idx][0] !== charArr[i] || arr[idx][1] < count || (arr[idx][1] <3 && arr[idx][1] !== count) ){
                flag = false;
                break
            }
            idx++;
            i++

        }
        if(idx !== arr.length)flag = false
        if(flag)ans++
    }
    return ans
};