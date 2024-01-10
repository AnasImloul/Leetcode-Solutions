// Runtime: 63 ms (Top 69.02%) | Memory: 44.30 MB (Top 49.02%)

/**
 * @param {number} numOnes
 * @param {number} numZeros
 * @param {number} numNegOnes
 * @param {number} k
 * @return {number}
 */
var kItemsWithMaximumSum = function(numOnes, numZeros, numNegOnes, k) {
        let result =0
        for(let i=1;i<=k;i++){
            if(i<=numOnes){
                result+=1
            }else if(i<=numZeros+numOnes){
                result+=0
            }else if(numZeros+numOnes+numNegOnes){
                result-=1

            }

        }
    
    return result 
};
