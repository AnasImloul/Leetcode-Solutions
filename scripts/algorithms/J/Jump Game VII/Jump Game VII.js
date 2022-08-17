var canReach = function(s, minJump, maxJump) {
    const validIdxs = [0];
    for (let i = 0; i < s.length; i++) {
        // skip if character is a 1 or if all the 
        // valid indicies are too close
        if (s[i] === '1' || i - validIdxs[0] < minJump) {
            continue;
        }
        
        // remove all the indexes that are too far
        while (validIdxs.length && i - validIdxs[0] > maxJump) {
            validIdxs.shift();
        }
        if (validIdxs.length === 0) {
            return false;
        }
        
        validIdxs.push(i);
        
        // if we are at the last index
        // return if we have an index within range
        if (i === s.length - 1) {
            return i - validIdxs[0] >= minJump;
        }
    }
    // if the last character is a 1 we must return False
    return false;
};
