/** https://leetcode.com/problems/video-stitching/
 * @param {number[][]} clips
 * @param {number} time
 * @return {number}
 */
var videoStitching = function(clips, time) {
  // Memo
  this.memo = new Map();
  
  // Sort the clips for easier iteration
  clips.sort((a, b) => a[0] - b[0]);
  
  // If the output is `Infinity` it means the task is impossible
  let out = dp(clips, time, 0, -1);
  return out === Infinity ? -1 : out;
};

var dp = function(clips, time, index, endTime) {
  let key = `${index}_${endTime}`;
  
  // Base, we got all the clip we need
  if (endTime >= time) {
    return 0;
  }
  
  // Reach end of the clip array
  if (index === clips.length) {
    return Infinity;
  }
  
  // Return form memo
  if (this.memo.has(key) === true) {
    return this.memo.get(key);
  }
  
  // There are 2 choices, include clip in current `index` or exclude
  // Include clip in current `index`
  let include = Infinity;
  
  // We can only include clip in current `index` if either:
  // - the `endTime` is -1 and current clip's starting is 0, in which this clip is the first segment
  // - the `endTime` is greater than current clip's starting time, in which this clip has end time greater than our `endTime`
  if ((endTime < 0 && clips[index][0] === 0) ||
      endTime >= clips[index][0]) {
    // Update the next `endTime` with the current clip's end time, `clips[index][1]`
    let nextEndTime = clips[index][1];
    include = 1 + dp(clips, time, index + 1, nextEndTime);
  }
  
  // Exclude clip in current `index`
  let exclude = dp(clips, time, index + 1, endTime);
  
  // Find which one has less clips
  let count = Math.min(include, exclude);
  
  // Set memo
  this.memo.set(key, count);
  
  return count;
};
