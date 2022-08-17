/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function(dominoes) {
    
    let len = dominoes.length;
    let fall = [];
    let force = 0;
    let answer = "";
    
    // Traverse from left to right. Focus on the dominoes falling to the right
    for (let i = 0; i < len; i++) {
        if (dominoes[i] == 'R') {
            force = len;
        } else if (dominoes[i] == 'L') {
            force = 0;
        } else {
            force = Math.max(force-1,0);
        }
        fall[i] = force;
    }
    
    //console.log('fall array 1: ', fall);
    
    // Traverse from right to left. Focus on the dominoes falling to the left
    // Subtract the value from the values above
    for (let i = len-1; i >= 0; i--) {
        if (dominoes[i] == 'L') {
            force = len;
        } else if (dominoes[i] == 'R') {
            force = 0;
        } else {
            force = Math.max(force-1,0);
        }
        fall[i] -= force;
    }    
    
    //console.log('fall array 2: ', fall);
    
    // Just traverse through the fall[] array and assign the values in the answer string accordingly
    for (let i = 0; i < len; i++) {
        if (fall[i] < 0)
            answer += 'L';
        else if (fall[i] > 0 )
            answer += 'R';
        else
            answer += '.';
    }
    
    //console.log('answer: ', answer);
    
    return answer;
    
};
