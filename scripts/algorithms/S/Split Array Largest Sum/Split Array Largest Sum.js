// Runtime: 50 ms (Top 77.73%) | Memory: 49.00 MB (Top 11.74%)

var splitArray = function(nums, m) {
    let low = Math.max(...nums);
    let high = 0;
    let ans = 0;
    
    for(let num of nums) {
        high += num;
    }
    
    while(low <= high) {
        let mid = Math.floor(low + (high - low) / 2); // to prevent overflow
        
        if(isPossible(nums, mid, m)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
};

function isPossible(arr, mid, noOfParts) {
    let part = 1;
    let sum = 0;
    
    for(let i = 0; i < arr.length; i++) {
        sum += arr[i];
        
        if(sum > mid) {
            part++;
            sum = arr[i];
        }
    }
    return part <= noOfParts; 
}
