/**
 * @param {number} buckets
 * @param {number} minutesToDie
 * @param {number} minutesToTest
 * @return {number}
 */
var poorPigs = function(buckets, minutesToDie, minutesToTest) {
  let answer = 1;
  let n = minutesToTest / minutesToDie >> 0;
  n += 1;
  
  // calculation with loop
  // while(n ** answer <= buckets) {
  //   answer++;
  // }
  
  return Math.ceil(Math.log(buckets) / Math.log(n));
};

