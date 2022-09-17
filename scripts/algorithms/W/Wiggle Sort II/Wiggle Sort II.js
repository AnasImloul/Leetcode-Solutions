// Runtime: 133 ms (Top 67.12%) | Memory: 47 MB (Top 71.23%)

var wiggleSort = function(nums) {
    nums.sort((a,b) => a - b);

    let temp = [...nums];

    let low = Math.floor((nums.length-1)/2), high = nums.length-1;

    for(let i=0; i < nums.length; i++){
        if(i % 2 === 0){
            nums[i] = temp[low];
            low--;
        }else{
            nums[i] = temp[high];
            high--;
        }
    }

    return nums;
};