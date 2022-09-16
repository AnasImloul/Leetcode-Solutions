// Runtime: 192 ms (Top 11.57%) | Memory: 47.5 MB (Top 5.66%)
var singleNumber = function(nums) {
    let hash ={}
    for ( let num of nums){
        if( hash[num]===undefined)
            hash[num] =1
        else
            hash[num]++
    }

    let result =[]
    for ( let [key, value] of Object.entries(hash)){
         if(value==1)
         result.push(key)
    }
    return result
};