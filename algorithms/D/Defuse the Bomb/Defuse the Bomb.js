/**
 * @param {number[]} code
 * @param {number} k
 * @return {number[]}
 */
var decrypt = function(code, k) {
    var res = new Array(code.length).fill(0)
    if (k > 0){
            for(var i = 0; i < code.length; i++){
            var count = 0
            var j = i + 1
            while(count < k){
                if (j === code.length) j = 0
                res[i] += code[j]
                count = count + 1
                j++
            }
        }
    }
    if (k < 0){
            for(var i = 0; i < code.length; i++){
            var count = 0
            var j = i - 1
            while(count > k){
                if (j === -1) j = code.length - 1
                res[i] += code[j]
                count = count - 1
                j--
            }
        }
    }
    return res 
};
