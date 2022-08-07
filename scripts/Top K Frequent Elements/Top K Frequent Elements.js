var topKFrequent = function(nums, k) {
  let store = {};
    for(let i=0;i<nums.length;i++){
        store[nums[i]] = store[nums[i]]+1||1
    }
    //returns an array of keys in sorted order
    let keyArr = Object.keys(store).sort((a,b)=>store[a]-store[b])
    let arrLength = keyArr.length;
    let slicedArr = keyArr.slice(arrLength-k,arrLength)
    return slicedArr
};
