/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
//    1. create hashmap with "balloon" letters
//    2. keep track of how many letters in text belong to "balloon"
//     3. account for fact that we need two "l" and "o" per "balloon" instance
//    4. then select all map values and get the minimum - this will be the max value
    
    const balloonMap = {
        "b": 0,
        "a": 0,
        "l": 0,
        "o": 0,
        "n": 0
    }
    
    for (const char of text) {
        if (balloonMap[char] !== undefined) {
            balloonMap[char] += 1
        }
    }
    
    const letterFreq = []
    for (const key in balloonMap) {
        if (["l", "o"].includes(key)) {
            letterFreq.push(Math.floor(balloonMap[key]/2))
        } else {
            letterFreq.push(balloonMap[key])
        }
    }
    return Math.min(...letterFreq)
};
