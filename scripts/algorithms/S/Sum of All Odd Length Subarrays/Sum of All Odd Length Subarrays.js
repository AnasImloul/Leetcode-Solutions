/*
Suppose N is the length of given array.
Number of subarrays including element arr[i] is
i * (N-i) + (N-i) because there are N-i subarrays with arr[i] as first element
and i * (N-i) subarrays with arr[i] as a not-first element. arr[i] appears in 
(N-i) subarrays for each preceding element and therefore we have i*(N-i).

Suppose i * (N-i) + (N-i) is `total`. Ceil(total / 2) is the number of odd-length subarrays and Floor(total / 2) is the number of even-length subarrays. 
When total is odd, there is one more odd-length subarray because of a single-element subarray.
    
For each number, we multiply its value with the total number of subarrays it appears and
add it to a sum.
*/
var sumOddLengthSubarrays = function(arr) {
    let sum = 0, N = arr.length;
    for (let i = 0; i < arr.length; i++) {
        let total = i * (N-i) + (N-i);
        sum += Math.ceil(total / 2) * arr[i];
    }
    return sum;
    // T.C: O(N)
    // S.C: O(1)
};
