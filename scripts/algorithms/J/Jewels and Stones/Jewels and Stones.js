var numJewelsInStones = function(jewels, stones) {
    let trackDict = new Map();
    let output = 0;

    for (let char of stones)
        trackDict.set(char, trackDict.has(char) ? trackDict.get(char) + 1 : 1);
    
    for (let char of jewels)
        output += trackDict.has(char) ? trackDict.get(char) : 0;

    return output;
};