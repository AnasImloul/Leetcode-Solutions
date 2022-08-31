// Runtime: 90 ms (Top 97.50%) | Memory: 51.9 MB (Top 80.00%)
var minSumOfLengths = function(arr, target) {
    let left=0;
    let curr=0;
    let res=Math.min(); // Math.min() without any args will be Infinite
    const best=new Array(arr.length).fill(Math.min());
    let bestSoFar=Math.min()

    for(let i=0;i<arr.length;i++){
        curr+=arr[i]
        while(curr>target){
            curr-=arr[left++]
        }
        if(curr===target){
            if(left>0&&best[left-1]!==Math.min()){
                res=Math.min(res,best[left-1]+i-left+1)
            }
            bestSoFar=Math.min(bestSoFar,i-left+1)
        }
        best[i]=bestSoFar;
    }
    return res===Math.min()?-1:res
};