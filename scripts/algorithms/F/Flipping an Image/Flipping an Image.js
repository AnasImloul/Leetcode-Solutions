// Runtime: 83 ms (Top 79.20%) | Memory: 44.5 MB (Top 14.19%)
var flipAndInvertImage = function(image) {
    const resversedArr = []
    for(let i=0; i<image.length; i++){
         resversedArr.push(resverseArr(image[i]));
    }
  return resversedArr;
};

function resverseArr(arr){
    const lastIndex = arr.length -1, reversedArr = [];
    for(i=0; i<=lastIndex; i++){
        if(arr[i] !== arr[lastIndex-i]){
            reversedArr[i] = arr[lastIndex-i] === 0 ? 1 : 0;
            reversedArr[lastIndex-i] = arr[i] === 0 ? 1 : 0;
        }else{
           reversedArr[i] = arr[i] === 0 ? 1 : 0;
        }
    }
    return reversedArr;
}```

/*
Runtime: 68 ms, faster than 96.46% of JavaScript online submissions for Flipping an Image.
Memory Usage: 44.4 MB, less than 16.91% of JavaScript online submissions for Flipping an Image.
*/