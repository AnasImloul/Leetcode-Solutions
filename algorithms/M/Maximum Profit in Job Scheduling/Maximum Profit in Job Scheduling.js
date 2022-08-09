var jobScheduling = function(startTime, endTime, profit) {
  const N = startTime.length;

  let zip = [];
  for(let i = 0; i < N; i++) {
    zip.push([startTime[i], endTime[i], profit[i]]);
  }
  const starts = mergesort(zip, (a, b) => a[0] - b[0]).map(s => s[0]);
  const endAsc = mergesort(zip, (a, b) => a[1] - b[1]);
  const ends = endAsc.map(s => s[1]);
  
  const startToClosestEnd = {};
  let j = 0;
  for(const start of starts) {
    let curEnd = ends[j];
    let nextEnd = ends[j+1];
    // While the current and next end are before the current start...
    while(curEnd <= start && nextEnd && nextEnd <= start) {
      // Advance one end.
      j++;
      curEnd = ends[j];
      nextEnd = ends[j+1];
    }
    
    if(curEnd <= start) {
      startToClosestEnd[start] = curEnd;
    } else {
      startToClosestEnd[start] = null;
    }
  }

  let maxProfit = Number.MIN_SAFE_INTEGER;
  
  const bestAtEnd = {};
  for(const [start, end, profit] of endAsc) {
    if(startToClosestEnd[start]) {
      maxProfit = Math.max(maxProfit, bestAtEnd[startToClosestEnd[start]] + profit);
    } else {
      maxProfit = Math.max(maxProfit, profit);
    }
    
    bestAtEnd[end] = maxProfit;
  }

  return maxProfit;
};

function mergesort(arr, comparator) {
  if(arr.length === 1) return arr;

  const mid = Math.floor((arr.length - 1) / 2);
  const a = mergesort(arr.slice(0, mid+1), comparator);
  const b = mergesort(arr.slice(mid+1), comparator);
  const c = [];

  while(a.length || b.length) {
    if(a.length && b.length) {
      if(comparator(a[0], b[0]) < 0) {
        c.push(a.shift());
      } else {
        c.push(b.shift());
      }
    } else if(b.length) {
      c.push(b.shift());
    } else {
      c.push(a.shift());
    }
  }

  return c;
}
