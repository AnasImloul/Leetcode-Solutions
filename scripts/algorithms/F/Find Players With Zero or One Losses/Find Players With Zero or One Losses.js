// Runtime: 735 ms (Top 32.40%) | Memory: 116.4 MB (Top 54.23%)
/**
 * @param {number[][]} matches
 * @return {number[][]}
 */
var findWinners = function(matches) {
    var looser = {};
    var allPlayer={};
    for(var i=0; i<matches.length; i++)
        {
            if(looser[matches[i][1]])
                looser[matches[i][1]]++;
            else
                looser[matches[i][1]]=1

            if(!allPlayer[matches[i][0]])
                allPlayer[matches[i][0]]=1
            if(!allPlayer[matches[i][1]])
                allPlayer[matches[i][1]]=1
        }
    var first=[], second=[];
    for(var key in allPlayer)
        {
            if(!looser[key])
                first.push(key);
            if(looser[key] == 1)
                second.push(key);
        }
    return [first, second]
};