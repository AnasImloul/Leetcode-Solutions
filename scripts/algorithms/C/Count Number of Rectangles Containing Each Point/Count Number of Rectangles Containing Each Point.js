var countRectangles = function(rectangles, points) {
  let buckets = Array(101).fill(0).map(() => []);
  for (let [x, y] of rectangles) {
    buckets[y].push(x);
  }
  for (let i = 0; i < 101; i++) buckets[i].sort((a, b) => a - b);

  let res = [];
  for (let point of points) {
    let sum = 0;
    for (let j = point[1]; j < 101; j++) {
      // lowest index >= point[0]
      let index = lower_bound(buckets[j], point[0]);
      sum += buckets[j].length - index;
    }
    res.push(sum);
  }
  return res;

  function lower_bound(arr, targ) {
    let low = 0, high = arr.length;
    while (low < high) {
      let mid = Math.floor((low + high) / 2);
      if (arr[mid] >= targ) high = mid;
      else low = mid + 1;
    }
    return low;
  }
};
