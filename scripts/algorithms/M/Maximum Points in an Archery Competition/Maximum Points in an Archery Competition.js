var maximumBobPoints = function(numArrows, aliceArrows) {
  let max = 0, n = aliceArrows.length, res;
  backtrack(numArrows, 0, 0, Array(n).fill(0));
  return res;

  function backtrack(arrows, idx, points, bobArrows) {
    if (idx === n || arrows === 0) {
      let origVal = bobArrows[n - 1];
      if (arrows > 0) bobArrows[n - 1] += arrows; // put extra arrows in any slot
      if (points > max) {
        max = points;
        res = [...bobArrows]; 
      }
      bobArrows[n - 1] = origVal;
      return;
    }

    backtrack(arrows, idx + 1, points, bobArrows); // don't use any arrows
    if (aliceArrows[idx] + 1 <= arrows) { // use aliceArrows[idx] + 1 arrows to gain idx points
      bobArrows[idx] = aliceArrows[idx] + 1;
      backtrack(arrows - (aliceArrows[idx] + 1), idx + 1, points + idx, bobArrows);
      bobArrows[idx] = 0;
    }
  }  
};
