var minSetSize = function(arr) {
  let halfSize = arr.length / 2;
  const numsCount = Object.values(getNumsCount(arr)).sort((a, b) => b - a); // get the frequencies in an array sorted in descending order
  let setSize = 0;
  if (numsCount[0] >= halfSize) return 1; // if the highest frequency is greater than or equal to half of the array size, then you already have your smallest set size of 1
  for (let i = 0; i < numsCount.length; i++) {
    let numCount = numsCount[i];
    if (halfSize > 0) {
      setSize++;
      halfSize -= numCount;
    } else {
      return setSize;
    };
  };
};

var getNumsCount = function (arr) {
  let eleCounts = {};
  for (let i = 0; i < arr.length; i++) {
    let num = arr[i];
    if (!eleCounts[num]) {
      eleCounts[num] = 1;
    } else {
      eleCounts[num]++;
    };
  };
  return eleCounts;
};
