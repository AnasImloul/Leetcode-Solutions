/**
 * @param {number[]} arr
 * @return {number}
 */
var countTriplets = function(arr) {
    let count = 0
    for(let i=0;i<arr.length;i++){
        let xor = arr[i]
        for(let j=i+1;j<arr.length;j++){
            xor ^= arr[j]
            if(xor == 0){
                count += (j-i)
            }
        }
    }
    return count
};
