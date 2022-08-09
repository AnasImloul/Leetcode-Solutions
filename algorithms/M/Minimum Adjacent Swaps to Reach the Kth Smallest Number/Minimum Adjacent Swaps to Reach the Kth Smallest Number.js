var getMinSwaps = function(num, k) {
    
    const digits = [...num]
    const len = digits.length;
    
    // helper function to swap elements in digits in place
    const swap = (i, j) => [digits[i], digits[j]] = [digits[j], digits[i]]
    
    // helper function to reverse elements in digits from i to the end of digits
    const reverse = (i) => {
        for (let j = len - 1; i < j; ++i && --j) {
            swap(i, j);
        }
    }
    
    // helper to get the next smallest permutation for digits
    const nextPermutation = () => {
        // from right to left, find the first decreasing index
        // in digits and store it as i
        let i = len - 2;
        while (digits[i] >= digits[i + 1]) {
            i--;
        }
        
        // from right to left, find the first index in digits
        // that is greater than element at i
        let j = len - 1;
        while (digits[j] <= digits[i]) {
            j--;
        }
        
        // swap the 2 elements at i and j
        swap(i, j);
        // reverse all elements after i because we know that
        // all elements after i are in ascending order
        // from right to left
        reverse(i + 1);
    }
    
    // find the next permutation k times
    for (let i = 0; i < k; i++) {
        nextPermutation();
    }

    // find out how many swaps it will take to get to the
    // kth permutation by finding out how many swaps
    // it takes to put digits back to its original state
    let numSwaps = 0;
    for (let i = 0; i < len; i++) {
        let j = i;
        // find the first element in digits to matches
        // num[i] and hold its place at j
        while (num[i] !== digits[j]) {
            j++;
        }
        
        // move the element at j to i while counting the
        // number of swaps
        while (i < j) {
            swap(j, j - 1);
            numSwaps++;
            j--;
        }
    }
    return numSwaps;
};
