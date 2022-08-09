/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var numberOfArrays = function(s, k) {
    var cache={};
    return backtrack(0)%1000000007;
    function backtrack(pos){
        let orignalPos = pos;
        if(cache[pos]!==undefined){
            return cache[pos];
        }
        let count=0;
        let digit=0;
        while(pos<s.length){
            digit = digit*10 + parseInt(s[pos]);
            if(digit<=k && pos+1<=s.length-1 && s[pos+1]!=='0'){//If we can call backtrack on next position. 
                count+=(backtrack(pos+1)%1000000007);
            }
            if(digit>k){
                break;
            }
            pos++;
        }    
        if(pos===s.length && digit<=k){//If this number became the only digit in the array, for string starting at position orignalPos. This also completed the etire string. 
            count++;
        }
        cache[orignalPos]=count;
        return count;
    }
};
