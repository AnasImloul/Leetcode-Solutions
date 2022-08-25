// Runtime: 158 ms (Top 57.36%) | Memory: 42.8 MB (Top 31.01%)
// counting bigger / smaller elements
// if after rating[i] has X bigger elements,
// and each element has Y bigger elements after them
// hence total elements that has i < j < k and rating[i] < rating[j] < rating[k]
// same for the number of smaller elements
// so the key point here is to know how many elements
// that smaller and bigger than the current number
var numTeams = function(rating) {
    // save total number of elements after i
    // that smaller than rating[i]
    let big = new Array(rating.length).fill(0)

    let n = rating.length;
    for (let i = 0; i < n - 1; i++) {
        for (let j = i + 1; j < n; j++) {
            if (rating[j] > rating[i]) big[i]++;
        }
    }

    let count = 0;
    for (let i = 0; i < n - 1; i++) {
        for (let j = i + 1; j < n; j++) {
            if (rating[j] > rating[i]) count += big[j]

            // because all elements are unique, so
            // we don't need to calculate the number of smaller elements
            // because if there are X bigger elements after rating[i]
            // then there are (n - i - 1 - X) smaller elements after rating[i]
            // or small = n - i - 1 - big
            else count += n - j - 1 - big[j];
        }
    }

    return count;
}