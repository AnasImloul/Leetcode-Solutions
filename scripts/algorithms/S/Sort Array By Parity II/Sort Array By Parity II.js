var sortArrayByParityII = function(nums) {
    let arrEven = []
    let arrOdd = []
    let result = []
    for(let i in nums){
    nums[i]%2==0 ? arrEven.push(nums[i]) : arrOdd.push(nums[i])
    }
    for(let i in  arrEven){
        result.push(arrEven[i])
        result.push(arrOdd[i])
    }
   return result
};
