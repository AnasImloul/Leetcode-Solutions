var prevPermOpt1 = function(arr) {
    const n = arr.length;
    let i = n - 1;
    
    while (i > 0 && arr[i] >= arr[i - 1]) i--;
    
    if (i === 0) return arr;

    const swapIndex = i - 1;
    const swapDigit = arr[swapIndex];
    
    let maxIndex = i;
    i = n - 1;
    
    while (swapIndex < i) {
        const currDigit = arr[i];
        
        if (currDigit < swapDigit && currDigit >= arr[maxIndex]) maxIndex = i;
        i--;
    }

    [arr[maxIndex], arr[swapIndex]] = [arr[swapIndex], arr[maxIndex]];
    
    return arr; 
}; 
