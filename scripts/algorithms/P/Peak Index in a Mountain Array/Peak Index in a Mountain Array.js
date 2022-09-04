// Runtime: 119 ms (Top 38.98%) | Memory: 51.6 MB (Top 23.92%)
var peakIndexInMountainArray = function(arr) {

    //lets assume we have peak it divides array in two parts
    // first part is increasing order , second part is decreasing
    // when we find the middle we'll compare arr[middle] > arr[middle+1], it means
    //we can only find max in first part of arr (increasing part) else second part.
    //there will be point where start === end that is our peak
    let start = 0;
    let end = arr.length -1;
    while(start < end){
        let mid = parseInt(start + (end - start)/2)
        if( arr[mid] > arr[mid + 1]){
            end = mid;
        }else {
            start = mid +1;
        }
    }

    return start;

};