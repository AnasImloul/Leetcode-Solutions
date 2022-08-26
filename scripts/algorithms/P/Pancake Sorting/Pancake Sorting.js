// Runtime: 134 ms (Top 20.79%) | Memory: 44.1 MB (Top 74.26%)
var pancakeSort = function(arr) {
let res = [];

for(let i=arr.length; i>0; i--){//search the array for all values from 1 to n
    let idx = arr.indexOf(i);
    if(idx!=i-1){// if value is not present at its desired index
        let pancake = arr.slice(0,idx+1).reverse();//flip the array with k=index of value i to put it in front of the array
        res.push(idx+1);
        arr = arr.slice(idx+1);
        arr = pancake.concat(arr);//value i is now at index 0
        pancake = arr.slice(0,i).reverse();//flip the array with k = i-1 to put the value at its place
        res.push(i);
        arr = arr.slice(i);
        arr = pancake.concat(arr);//now the array is sorted from i to n
    }
}
return res;
};