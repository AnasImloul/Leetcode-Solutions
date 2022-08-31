// Runtime: 104 ms (Top 57.56%) | Memory: 42 MB (Top 82.93%)
var countGoodTriplets = function(arr, a, b, c) {
  let triplets = 0;

  for (let i = 0; i < arr.length - 2; i++) {
    for (let j = i + 1; j < arr.length - 1; j++) {
      if (Math.abs(arr[i] - arr[j]) > a) continue;
      for (let k = j + 1; k < arr.length; k++) {
        if (Math.abs(arr[j] - arr[k]) > b || Math.abs(arr[i] - arr[k]) > c) {
          continue;
        }
        triplets++;
      }
    }
  }

  return triplets;
};