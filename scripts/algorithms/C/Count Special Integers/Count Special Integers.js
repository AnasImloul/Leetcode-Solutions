/**
 * @param {number} n
 * @return {number}
 */
var countSpecialNumbers = function(n) {
    const arr = []
    let count = 0
    let temp = n+1
    
    while(temp !== 0) {
        arr.unshift(temp%10)
        temp = Math.floor(temp/10)
    }
    
    for(let i = 0; i < arr.length - 1; i++) {
        count += 9*permutation(9,i)
    }
    
    const set = new Set()
    
    for(let i = 0; i < arr.length; i++) {
        for(let j = i===0?1:0; j < arr[i]; j++) {
            if(set.has(j)) continue
            count += permutation(10-(i+1), arr.length - 1 - i)
        }
        
        if(set.has(arr[i])) break
        set.add(arr[i])
    }
    
    return count
    
    function permutation(n, right){
        let nonRepeatingNums = 1
        
        for(let i = 0; i < right; i++) {
            nonRepeatingNums*=n
            n--
        }
        
        return nonRepeatingNums
    }
};