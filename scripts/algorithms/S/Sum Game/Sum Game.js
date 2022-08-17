/**
 * @param {string} num
 * @return {boolean}
 */
var sumGame = function(num) {
    
    function getInfo(s) {
        var sum = 0;
        var ques = 0;
        for(let c of s.split(''))
            if (c !== '?') sum += c - 0;
            else ques++;
        return [sum, ques];
    }
    
    function check(sum1, sum2, q1, q2, q) {
        return sum1 + 9* Math.min(q/2, q1) > sum2 + 9 * Math.min(q/2, q2);
    }
    
    
    var q = getInfo(num)[1];
    var [sum1, q1] = getInfo(num.substring(0, Math.floor(num.length/2)));
    var [sum2, q2] = getInfo(num.substring(Math.floor(num.length/2), num.length));
    if (sum1 < sum2) { 
        [sum1, sum2] = [sum2, sum1];
        [q1, q2] = [q2, q1];
    }
    
    return check(sum1, sum2, q1, q2, q) || check(sum2, sum1, q2, q1, q);
};