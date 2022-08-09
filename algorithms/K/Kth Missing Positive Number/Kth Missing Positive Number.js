var findKthPositive = function(arr, k) {
    let newArr = [];
    for(let i=0,j=1; j<=arr.length+k; j++){
        arr[i]!=j?newArr.push(j):i++;
    }
    return newArr[k-1]; 
    
};
