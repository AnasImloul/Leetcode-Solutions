// Runtime: 411 ms (Top 73.77%) | Memory: 86.1 MB (Top 45.90%)
/**
 * @param {number[]} nums
 * @param {number} pivot
 * @return {number[]}
 */
var pivotArray = function(nums, pivot) {

    let n=nums.length;

    //first Solution with 3 separet Array
    let lessPivot=[]
    let equalPivot=[]
    let bigerPivot=[]

    for(let i=0;i<n;i++){
        if(nums[i]<pivot)lessPivot.push(nums[i])
        else if(nums[i]===pivot)equalPivot.push(nums[i])
        else bigerPivot.push(nums[i])

    }
    return lessPivot.concat(equalPivot.concat(bigerPivot))

    //second Solution with one Array

    let result=[]
    for(let num of nums){
        if(num<pivot)result.push(num)
    }

    for(let num of nums){
        if(num===pivot)result.push(num)
    }
    for(let num of nums){
        if(num>pivot)result.push(num)
    }
    return result
};