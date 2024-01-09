// Runtime: 133 ms (Top 66.67%) | Memory: 48.20 MB (Top 50.0%)

var movesToStamp = function(stamp, target) {
    let res = [];
    let total_stamp = 0, turn_stamp = -1;
    while (turn_stamp) {
      turn_stamp = 0;
      for (let sz = stamp.length; sz > 0; --sz) 
          for (let i = 0; i <= stamp.length - sz; ++i) {
              let new_stamp = '*'.repeat(i) + stamp.slice(i, sz + i) + '*'.repeat(stamp.length - sz - i); // preparing 'abc', '*bc', 'ab*', 'a**' etc
              let pos = target.indexOf(new_stamp); // finding position of prepared new_stamp in target
              while (pos != -1) { // if position is found
                  res.push(pos); // then push position into response array
                  turn_stamp += sz; // sz is size on new_stamp without '*'. so for 'abc' sz equals 3, for 'a**' sz equals 1
                  target = target.slice(0, pos) + "*".repeat(stamp.length) + target.slice(pos + stamp.length); // insert new_stamp into target
                  pos = target.indexOf(new_stamp); // try to find another place in target where we can insert new_stamp
              }
          }
          total_stamp += turn_stamp;
      }
      res.reverse();
      return total_stamp == target.length ? res : []; // we check if all characters converted to '*'
};
