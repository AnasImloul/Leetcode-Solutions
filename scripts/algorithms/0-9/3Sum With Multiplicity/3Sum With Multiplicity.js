// Runtime: 141 ms (Top 80.77%) | Memory: 43.6 MB (Top 86.54%)

/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var threeSumMulti = function(arr, target) {
    let count=0
    arr.sort((a,b)=>a-b)
    for(let i=0;i<arr.length-2;i++){
        let j=i+1,k=arr.length-1
        while(j<k){
            let sum=arr[i]+arr[j]+arr[k]
            if(sum<target){
                j++
            }
            else if(sum>target){
                k--
            }
            else{
                if(arr[j]!==arr[k]){
                    let j1=j,k1=k
                    while(arr[j]===arr[j1]){
                        j1++
                    }
                    while(arr[k]===arr[k1]){
                        k1--
                    }
                    count+=((j1-j)*(k-k1))
                    j=j1
                    k=k1
                }
                else{
                    for(let n=1;n<=k-j;n++){
                        count+=n
                    }
                    break
                }
            }
        }
    }
    return count% (10**9 + 7)
};