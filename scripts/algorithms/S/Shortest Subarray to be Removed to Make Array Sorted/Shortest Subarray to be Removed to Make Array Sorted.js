var findLengthOfShortestSubarray = function(arr) {
    const n = arr.length;
    
    if (n <= 1) {
        return 0;
    }
    
    let prefix = 1;
    
    while (prefix < n) {
        if (arr[prefix - 1] <= arr[prefix]) {
            prefix++;
        } else {
            break;
        }
    }
    
    if (prefix === n) {
        return 0;
    }
    
    let suffix = 1;
    
    while (suffix < n) {
        const i = n - 1 - suffix;
        
        if (arr[i] <= arr[i + 1]) {
            suffix++;
        } else {
            break;
        }
    }

    let res = Math.min(n - prefix, n - suffix);
    let left = 0;
    let right = n - suffix;

    while (left < prefix && right < n) {
        if (arr[left] <= arr[right]) {
            res = Math.min(res, right - left - 1);
            left++;
        } else {
            right++;
        }
    }

    return res;
};
