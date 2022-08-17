var rectangleArea = function(rectangles) {
  let events = [], active = [], area = 0n;
  let mod = BigInt(1000000007);
  for (var rec of rectangles) {
    events.push([rec[1], 'open', rec[0], rec[2]]);
    events.push([rec[3], 'close', rec[0], rec[2]]);
  }  
  events = events.sort((a, b) => a[0] - b[0]);
  let y = events[0][0];
  for (var event of events) {
    let currY = event[0], type = event[1], x1 = event[2], x2 = event[3];
    let maxLength = 0, curr = -1;
    for (var ev of active) {
      curr = Math.max(curr, ev[0]);
      maxLength += Math.max(0, ev[1] - curr);
      curr = Math.max(curr, ev[1]);
    }
    area += (BigInt(maxLength) * BigInt(currY - y));
    area %= mod;
    if (type === 'open') {
      active.push([x1, x2]);
      active = active.sort((a, b) => a[0] - b[0]);
    } else {
      for (var i = 0; i < active.length; i++) {
        let e = active[i];
        if (e[0] === x1 && e[1] === x2) {
          active.splice(i, 1);
          break;
        }
      }
    }
    y = currY;
  }
  return area % mod;
};
