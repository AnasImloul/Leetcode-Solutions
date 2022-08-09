/**
 * @param {number[]} arr
 * @return {number}
 */
var maximumSum = function(arr) {
    let n = arr.length
     let fw = [];
    let bw = []; 
    let sum = arr[0]
    let max = arr[0];
  
    fw[0] = arr[0];

    for(let i = 1; i < n; i++){
        sum = Math.max(arr[i], sum + arr[i]);
        max = Math.max(max, sum);
  
        fw[i] = sum;
    } 
     
    sum =  arr[n-1]
    max = arr[n-1]
    bw[n - 1] = arr[n - 1];
     for(let i = n - 2; i >= 0; i--){
        sum = Math.max(arr[i], sum + arr[i]);
        max = Math.max(max, sum);
         bw[i] = sum;
    } 
  
    let fans = max; 
    for(let i = 1; i < n - 1; i++)
        fans = Math.max(fans, fw[i - 1] +
                              bw[i + 1]);
    return fans;
};