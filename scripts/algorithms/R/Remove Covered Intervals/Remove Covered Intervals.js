var removeCoveredIntervals = function(intervals) {
  intervals.sort((a,b)=> a[0]-b[0] || b[1]-a[1]);
  let overlap=0;
  for (i=1,prev=0; i<intervals.length; i++)
//    if ((intervals[prev][0] <= intervals[i][0]) //no need to check, already done in sort
//      && (intervals[prev][1] >= intervals[i][1]))
	if (intervals[prev][1] >= intervals[i][1]) // just look at 2nd index
      overlap++  // add to skipped elements
    else
      prev=i; // didn't overlap, so we can advance our previous element
  return intervals.length-overlap;
};
