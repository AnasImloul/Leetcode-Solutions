// Runtime: 127 ms (Top 24.62%) | Memory: 48.3 MB (Top 25.38%)
var subsetXORSum = function(nums) {
    let output=[];
    backtrack();
    return output.reduce((a,b)=>a+b);
    function backtrack(start = 0, arr=[nums[0]]){
       output.push([...arr].reduce((a,b)=>a^b,0));
       for(let i=start; i<nums.length; i++){
            arr.push(nums[i]);
            backtrack(i+1, arr);
            arr.pop();
       }
    }
};