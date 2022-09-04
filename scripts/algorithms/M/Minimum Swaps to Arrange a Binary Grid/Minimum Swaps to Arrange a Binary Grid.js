// Runtime: 124 ms (Top 66.67%) | Memory: 48.7 MB (Top 33.33%)
var minSwaps = function(grid) {
    const arr = [];
    let count = 0;

    for(let row of grid) {
        arr.push(row.lastIndexOf(1));
    }

    function swap(i, j) {
        [arr[i], arr[j]] = [arr[j], arr[i]];
        count++;
    }

    for(let i = 0; i < arr.length; i++) {
        // if num <= i pass b/c it's its correct spot
        if(arr[i] <= i) continue;
        let j = i;

        // scan forward looking for a num <= i
        while(arr[j] > i) {
            j++;
            if(j >= arr.length) return -1;
        }

        // swap as you move back to the right spot
        for(let k = j; k > i; k--) {
            swap(k, k-1);
        }
    }
    return count;
};