// Runtime: 135 ms (Top 34.29%) | Memory: 45.5 MB (Top 45.71%)
var isPossible = function(target) {
    let max=0
    let index=-1

    for(let i=target.length-1;i>=0;i--){
        if(target[i]>max){
            max=target[i]
            index=i
        }
    }
    if(max===1)return true // if max itself is 1 return true

    let total=0
    for(let i=0;i<target.length;i++){
        if(i!==index){
            total+=target[i]
        }
    }
    // If total=1,it means only one element was remaining apart from max and its value is 1 return true
    // eg target=[10,1] we started with [1,1] so next steps would be [2,1]->[3,1]->...[10,1] we can make sure it leads to target
    if(total===1)return true;
     // max should be greater than remaining nums sum OR if total is 0 it would lead to infinite loop( num%0 === NaN) so return false
    if(max<=total||total===0)return false;
    max=max%total;
    if(max<1)return false; // it should not be less than 1
    target[index]=max;

    return isPossible(target)
};