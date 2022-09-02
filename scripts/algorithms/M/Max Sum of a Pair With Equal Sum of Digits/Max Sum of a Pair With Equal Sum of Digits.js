// Runtime: 694 ms (Top 19.67%) | Memory: 88 MB (Top 12.50%)
var maximumSum = function(nums) {
    let sums = nums.map(x => x.toString().split('').map(Number).reduce((a,b)=> a+b,0));
    let max = -1;
    let map =sums.reduce((a,b,c) => {
        a[b] ??= [];
        a[b].push(nums[c])
        return a;
    },{});
    Object.values(map).forEach(x => {
        if(x.length > 1){
            let temp = x.sort((a,b) => b-a);
            max = Math.max(max, temp[0]+temp[1]);
        }
    })
    return max;
};