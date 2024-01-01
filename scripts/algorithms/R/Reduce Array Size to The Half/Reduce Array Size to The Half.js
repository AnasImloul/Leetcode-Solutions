// Runtime: 105 ms (Top 71.97%) | Memory: 57.90 MB (Top 93.94%)

var minSetSize = function(arr) {
  let half = arr.length / 2
  if (half === 1) return 1
  const counts = {}
  for (let n of arr) {
    if (counts[n] === undefined) counts[n] = 1
    else if (++counts[n] >= half) return 1
  }
  const aggr = Object.values(counts).sort((a, b) => a - b)
  let i = aggr.length;
  while (half > 0) half -= aggr[--i]
  return aggr.length - i
}
