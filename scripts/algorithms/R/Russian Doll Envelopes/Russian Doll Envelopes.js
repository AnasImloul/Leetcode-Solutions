const binarySearch = (arr, target) => {
    let left = 0;
    let right = arr.length - 1;
    
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] === target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}

var maxEnvelopes = function(envelopes) {
    envelopes.sort((a, b) => a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]);
    const sub = [envelopes[0][1]];
    
    for (let envelope of envelopes) {
        if (envelope[1] > sub[sub.length - 1]) {
            sub.push(envelope[1]);
        } else {
            const replaceIndex = binarySearch(sub, envelope[1]);
            sub[replaceIndex] = envelope[1];
        }
    }
    
    return sub.length;
};
