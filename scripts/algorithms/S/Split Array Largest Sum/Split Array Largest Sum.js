// Runtime: 2555 ms (Top 5.03%) | Memory: 70 MB (Top 5.53%)
var splitArray = function(nums, m) {
const n = nums.length;
var mat = [];
var sumArr = [nums[0]];
for(let i=1; i<n; i++){
    sumArr.push(sumArr[i-1]+nums[i]);//find prefix sum
}
mat.push(sumArr);
for(let i=0; i<n-1;i++){//form prefix matrix, i.e. every row i shows prefix sum starting from i
    let arr = new Array(n).fill(0);
    for(let j=i+1; j<n; j++){
        arr[j] = sumArr[j] - sumArr[i];
    }
    mat.push(arr);
}
let memo = new Map();
let recursion = (m,lastPartition) => {// recursive partition finder
    if(memo[m+'_'+lastPartition]!==undefined){
        return memo[m+'_'+lastPartition];//memoised
    }
    if(m==1){//base case, only 1 partition left
        memo[m+'_'+lastPartition] = mat[lastPartition][mat[0].length-1];
        return memo[m+'_'+lastPartition];
    }
    let min = Infinity;
    let maxSum = -Infinity;
    let lastval = Infinity;
    for(let i = lastPartition; i<=n-m; i++){//for mth partition, find the min sum for all possible partition placements
        while(i>0 && i<n-m && mat[lastPartition][i] == lastval) i++;//if a large set of values are repeating, i.e. a lot of 0s in original array, skip them
        lastval = mat[lastPartition][i];
        maxSum = Math.max(mat[lastPartition][i],recursion(m-1,i+1));//max of current subarray sum with max from the rest of the partitions
        min = Math.min(min, maxSum);//minimum sum for all the possible partition values
    }
    memo[m+'_'+lastPartition] = min;
    return memo[m+'_'+lastPartition];
}
return recursion(m,0);
};